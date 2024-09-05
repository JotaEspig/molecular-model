#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "axolote/scene.hpp"
#include "axolote/utils/grid.hpp"

#include "app.hpp"
#include "atom.hpp"
#include "bond.hpp"

void App::process_input(double dt) {
    Window::process_input(dt);
}

void App::main_loop() {
    _root_path = PROJECT_DIR;
    glfwSetWindowUserPointer(window(), this);
    set_color({0.9f, 0.9f, 0.9f, 0.5f});

    auto grid_shader = axolote::gl::Shader::create(
        get_path("resources/shaders/grid_base_vertex_shader.glsl"),
        get_path("resources/shaders/grid_base_fragment_shader.glsl")
    );
    auto object_shader = axolote::gl::Shader::create(
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

    auto atomA = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    atomA->is_affected_by_lights = true;

    auto atomB = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    atomB->is_affected_by_lights = true;

    auto bond = std::make_shared<Bond>(atomA, atomB);
    bond->bind_shader(object_shader);
    bond->is_affected_by_lights = true;

    auto dir_light = std::make_shared<axolote::DirectionalLight>(
        glm::vec4{1.0f}, true, glm::vec3{-1.0f, -0.5f, -1.0f}
    );

    scene->add_drawable(atomA);
    scene->add_drawable(atomB);
    scene->add_drawable(bond);
    scene->add_light(dir_light);
    scene->set_grid(grid);

    set_scene(scene);

    double last_time = get_time();
    while (!should_close()) {
        clear();

        double current_time = get_time();
        double dt = current_time - last_time;
        last_time = current_time;

        // Rotate atom A around y-axis
        const float dist = 4.0f;
        glm::vec3 posA{std::cos(current_time) * dist, 0.0f, std::sin(current_time) * dist};
        atomA->set_matrix(glm::translate(glm::mat4{1.0f}, posA));

        // Rotate atom B around x-axis
        glm::vec3 posB{0.0f, std::sin(current_time) * dist, std::cos(current_time) * dist};
        atomB->set_matrix(glm::translate(glm::mat4{1.0f}, posB));

        poll_events();
        process_input(dt);

        update_camera((float)width() / height());
        update(dt);
        render();

        flush();
    }
}
