#include "axolote/scene.hpp"

#include "app.hpp"

void App::process_input(double dt) {
    Window::process_input(dt);
}

void App::main_loop() {
    _root_path = PROJECT_DIR;
    glfwSetWindowUserPointer(window(), this);
    set_color({0.2f, 0.3f, 0.3f, 0.5f});

    auto scene = std::make_shared<axolote::Scene>();
    set_scene(scene);

    double last_time = glfwGetTime();
    while (!glfwWindowShouldClose(window())) {
        clear();

        double current_time = glfwGetTime();
        double dt = current_time - last_time;
        last_time = current_time;

        poll_events();
        process_input(dt);
        render();

        flush();
    }
}