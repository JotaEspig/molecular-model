#include <glm/gtc/matrix_transform.hpp>

#include "axolote/scene.hpp"
#include "axolote/utils/grid.hpp"

#include "app.hpp"
#include "atom.hpp"
#include "bond.hpp"

void App::process_input(double dt) {
    (void)dt;
    if (get_key_state(Key::ESCAPE) == KeyState::PRESSED)
        set_should_close(true);

    auto speed = current_scene()->camera.speed;
    if (get_key_state(Key::W) == KeyState::PRESSED)
        radius = std::max(radius - (double)speed * dt, 0.1);
    if (get_key_state(Key::S) == KeyState::PRESSED)
        radius += speed * dt;

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
        lat = glm::clamp(
            (float)lat, -M_PIf * 0.5f + 0.01f, M_PIf * 0.5f - 0.01f
        );
        set_cursor_position(half_center_x, half_center_y);
    }
    if (get_mouse_key_state(MouseKey::RIGHT) == MouseKeyState::RELEASED) {
        set_cursor_mode(CursorMode::NORMAL);
        current_scene()->camera.first_click = true;
    }

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
    object_shader = axolote::gl::Shader::create(
        get_path("resources/shaders/object3d_base_vertex_shader.glsl"),
        get_path("resources/shaders/object3d_base_fragment_shader.glsl")
    );

    auto scene = std::make_shared<axolote::Scene>();
    scene->camera.pos = {0.0f, 0.0f, 12.35f};
    scene->camera.speed = 3.0f;
    scene->camera.sensitivity = 10000.0f;
    scene->ambient_light_intensity = 0.2f;

    auto grid = std::make_shared<axolote::utils::Grid>(
        70, 5, true, glm::vec4{1.0f, 0.0f, 0.0f, 1.0f}
    );
    grid->bind_shader(grid_shader);

    auto dir_light = std::make_shared<axolote::DirectionalLight>(
        glm::vec4{1.0f}, true, glm::vec3{-1.0f, -0.5f, -1.0f}
    );

    scene->add_light(dir_light);
    scene->set_grid(grid);
    set_scene(scene);

    // Construct benzen
    const float r = 4.0f;
    const float angle_step = M_PIf / 3.0f;

    // Create carbons and hydrogens
    std::shared_ptr<Atom> carbons[6];
    std::shared_ptr<Atom> hydrogens[6];
    for (int i = 0; i < 6; ++i) {
        float x = std::cos(angle_step * (float)i) * r;
        float y = std::sin(angle_step * (float)i) * r;

        carbons[i] = add_carbon(glm::vec3{x, 0.0f, y});
        hydrogens[i] = add_hydrogen(glm::vec3{x, 0.0f, y} * 1.5f);
    }

    // Create bonds
    for (int i = 0; i < 6; ++i) {
        Bond::Type type = (i % 2) ? Bond::Type::Double : Bond::Type::Singular;

        add_bond(carbons[i], carbons[(i + 1) % 6], type);
        add_bond(carbons[i], hydrogens[i], Bond::Type::Singular);
    }

    double last_time = get_time();
    while (!should_close()) {
        clear();

        double current_time = get_time();
        double dt = current_time - last_time;
        last_time = current_time;

        poll_events();
        process_input(dt);

        update_camera((float)width() / height());
        update(dt);
        render();

        flush();
    }
}

std::shared_ptr<Atom> App::add_carbon(const glm::vec3 &pos) {
    auto carbon = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    carbon->is_affected_by_lights = true;
    carbon->set_matrix(glm::translate(glm::mat4{1.0f}, pos));
    current_scene()->add_drawable(carbon);
    return carbon;
}

std::shared_ptr<Atom> App::add_hydrogen(const glm::vec3 &pos) {
    auto hydrogen = std::make_shared<Atom>(glm::vec4{0.4f, 0.8f, 1.0f, 1.0f});
    hydrogen->is_affected_by_lights = true;

    glm::mat4 mat{1.0f};
    mat = glm::translate(mat, pos);
    mat = glm::scale(mat, glm::vec3{0.5f});
    hydrogen->set_matrix(mat);
    current_scene()->add_drawable(hydrogen);
    return hydrogen;
}

std::shared_ptr<Bond> App::add_bond(
    const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b,
    Bond::Type type
) {
    auto bond = std::make_shared<Bond>(a, b);
    bond->set_type(type);
    bond->bind_shader(object_shader);
    bond->is_affected_by_lights = true;
    current_scene()->add_drawable(bond);

    return bond;
}
