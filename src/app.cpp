#include <glm/gtc/matrix_transform.hpp>

#include "axolote/scene.hpp"
#define DEBUG
#include "axolote/utils.hpp"
#include "axolote/utils/grid.hpp"

#include "app.hpp"
#include "atom.hpp"
#include "bond.hpp"
#include "molecule.hpp"

#ifdef _WIN32
double clamp(double value, double min, double max) {
    return std::max(std::min(value, max), min);
}
const float M_PIf = 3.14159265358979323846f;
#endif

void App::process_input(double dt) {
    if (get_key_state(Key::ESCAPE) == KeyState::PRESSED)
        set_should_close(true);

    const float zoom_speed = 2.0f;
    const float move_speed = 0.5f;
    auto speed = current_scene()->camera.speed;
    if (get_key_state(Key::W) == KeyState::PRESSED)
        radius -= speed * zoom_speed * dt;
    if (get_key_state(Key::S) == KeyState::PRESSED)
        radius += speed * zoom_speed * dt;
    if (get_key_state(Key::A) == KeyState::PRESSED)
        lon += speed * move_speed * dt;
    if (get_key_state(Key::D) == KeyState::PRESSED)
        lon -= speed * move_speed * dt;
    if (get_key_state(Key::SPACE) == KeyState::PRESSED)
        lat += speed * move_speed * dt;
    if (get_key_state(Key::LEFT_SHIFT) == KeyState::PRESSED)
        lat -= speed * move_speed * dt;

    if (get_mouse_key_state(MouseKey::RIGHT) == MouseKeyState::PRESSED) {
        set_cursor_mode(CursorMode::DISABLED);

        double half_center_x = (double)width() * 0.5f;
        double half_center_y = (double)height() * 0.5f;
        if (current_scene()->camera.first_click) {
            current_scene()->camera.first_click = false;
            set_cursor_position(half_center_x, half_center_y);
        }

        double mouse_x, mouse_y;
        get_cursor_position(&mouse_x, &mouse_y);
        lon += (mouse_x - half_center_x) * dt;
        lat += (mouse_y - half_center_y) * dt;
        set_cursor_position(half_center_x, half_center_y);
    }
    if (get_mouse_key_state(MouseKey::RIGHT) == MouseKeyState::RELEASED) {
        set_cursor_mode(CursorMode::NORMAL);
        current_scene()->camera.first_click = true;
    }

#ifdef _WIN32
    lat = clamp(lat, -M_PIf * 0.5f + 0.01f, M_PIf * 0.5f - 0.01f);
#else
    lat = glm::clamp(
        (float)lat, -M_PIf * 0.5f + 0.01f, M_PIf * 0.5f - 0.01f
    );
#endif

    radius = std::max(radius, 0.1f);

    float x = std::cos(lat) * std::cos(lon);
    float y = std::sin(lat);
    float z = std::cos(lat) * std::sin(lon);
    auto pos = glm::vec3{x, y, z} * radius;
    current_scene()->camera.pos = pos;
    current_scene()->camera.orientation = glm::normalize(-pos);
}

void App::main_loop() {
    _root_path = PROJECT_DIR;
    glfwSetWindowUserPointer(window(), this);
    set_color({0.1f, 0.1f, 0.1f, 0.5f});

    auto grid_shader = axolote::gl::Shader::create(
        get_path("resources/shaders/grid_base_vertex_shader.glsl"),
        get_path("resources/shaders/grid_base_fragment_shader.glsl")
    );

    auto scene = std::make_shared<axolote::Scene>();
    scene->camera.pos = {0.0f, 0.0f, 12.35f};
    scene->camera.speed = 3.0f;
    scene->camera.sensitivity = 10000.0f;
    scene->ambient_light_intensity = 0.2f;

    auto grid = std::make_shared<axolote::utils::Grid>(
        70, 5, true, glm::vec4{1.0f, 0.0f, 0.0f, 1.0f}
    );
    grid->fading_factor = 70.0f;
    grid->bind_shader(grid_shader);

    auto dir_light = std::make_shared<axolote::DirectionalLight>(
        glm::vec4{1.0f}, true, glm::vec3{-1.0f, -0.5f, -1.0f}
    );

    scene->add_light(dir_light);
    scene->set_grid(grid);
    set_scene(scene);

    // Construct methane
    glm::mat4 methane_mat{1.0f};
    methane_mat = glm::rotate(methane_mat, glm::radians(45.0f), glm::vec3{1.0f, 0.0f, 0.0f});
    methane_mat = glm::rotate(methane_mat, glm::radians(60.0f), glm::vec3{0.0f, 1.0f, 0.0f});
    auto methane = create_methane(glm::vec3{-10.0f, 0.0f, 0.0f}, 2.0f, methane_mat);
    scene->add_drawable(methane);

    // Construct benzen
    const float r = 4.0f;
    const float angle_step = M_PIf / 3.0f;

    auto benzene = std::make_shared<Molecule>();
    // Create carbons and hydrogens
    std::shared_ptr<Atom> carbons[6];
    std::shared_ptr<Atom> hydrogens[6];
    for (int i = 0; i < 6; ++i) {
        float x = std::cos(angle_step * (float)i) * r;
        float y = std::sin(angle_step * (float)i) * r;
        carbons[i] = benzene->add_carbon(glm::vec3{x, 0.0f, y});
        hydrogens[i] = benzene->add_hydrogen(glm::vec3{x, 0.0f, y} * 1.5f);
    }

    // Create bonds
    for (int i = 0; i < 6; ++i) {
        Bond::Type type = (i % 2) ? Bond::Type::DOUBLE : Bond::Type::SINGULAR;
        benzene->add_bond(carbons[i], carbons[(i + 1) % 6], type);
        benzene->add_bond(carbons[i], hydrogens[i], Bond::Type::SINGULAR);
    }

    scene->add_drawable(benzene);

    double last_time = get_time();
    int second_counter = 0;
    while (!should_close()) {
        clear();

        double current_time = get_time();
        double dt = current_time - last_time;
        last_time = current_time;

        if (current_time - second_counter >= 5.0) {
            second_counter = current_time;
            axolote::debug("FPS: %.1lf", 1.0 / dt);
        }

        poll_events();
        process_input(dt);

        update_camera((float)width() / height());
        update(dt);
        render();

        flush();
    }
}
