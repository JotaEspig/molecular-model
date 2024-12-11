#include <algorithm>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>

#include "axolote/scene.hpp"
#define DEBUG // Enables debug function
#include "axolote/utils.hpp"
#include "axolote/utils/grid.hpp"

#include "app.hpp"
#include "atom.hpp"
#include "molecule.hpp"
#include "parser/lib.hpp"

#ifdef _WIN32
double clamp(double value, double min, double max) {
    return std::max(std::min(value, max), min);
}
const float M_PIf = 3.14159265358979323846f;
#endif

std::vector<axolote::Vertex> image_2d_vertices{
    {{-1.0f, -1.0f, 0.0f}, {}, {0.0f, 0.0f}, {}},
    {{1.0f, -1.0f, 0.0f}, {}, {1.0f, 0.0f}, {}},
    {{1.0f, 1.0f, 0.0f}, {}, {1.0f, 1.0f}, {}},
    {{-1.0f, 1.0f, 0.0f}, {}, {0.0f, 1.0f}, {}}
};
std::vector<GLuint> image_2d_indices{0, 1, 2, 0, 2, 3};

void App::process_input(double dt) {
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
    lat = glm::clamp((float)lat, -M_PIf * 0.5f + 0.01f, M_PIf * 0.5f - 0.01f);
#endif

    radius = std::max(radius, 0.1f);

    float x = std::cos(lat) * std::cos(lon);
    float y = std::sin(lat);
    float z = std::cos(lat) * std::sin(lon);
    auto pos = glm::vec3{x, y, z} * radius;
    current_scene()->camera.pos = pos;
    current_scene()->camera.orientation = glm::normalize(-pos);

    // Stops if there is no molecule to interact with
    if (current_molecule == nullptr)
        return;

    if (get_mouse_key_state(MouseKey::LEFT) == MouseKeyState::PRESSED
        && mouse_pressed == false) {
        double mouse_x, mouse_y;
        get_cursor_position(&mouse_x, &mouse_y);
        glm::vec3 ray = current_scene()->camera.get_ray(
            (float)mouse_x, (float)mouse_y, (float)width(), (float)height()
        );

        std::vector<std::shared_ptr<Atom>> intersected_atoms;
        for (auto &atom : current_molecule->atoms) {
            if (atom->intersect(current_scene()->camera.pos, ray)) {
                intersected_atoms.push_back(atom);
            }
        }
        std::sort(
            intersected_atoms.begin(), intersected_atoms.end(),
            [this](auto &a, auto &b) {
                glm::vec3 pos_a = a->get_matrix()[3];
                glm::vec3 pos_b = b->get_matrix()[3];
                return glm::distance(pos_a, current_scene()->camera.pos)
                       < glm::distance(pos_b, current_scene()->camera.pos);
            }
        );

        if (intersected_atoms.size() > 0) {
            if (currently_highlighted
                && currently_highlighted != intersected_atoms[0]) {
                currently_highlighted->highlighted = false;
            }
            currently_highlighted = intersected_atoms[0];
            currently_highlighted->highlighted
                = !currently_highlighted->highlighted;
        }

        mouse_pressed = true;
    }
    else if (get_mouse_key_state(MouseKey::LEFT) == MouseKeyState::RELEASED
             && mouse_pressed == true) {
        mouse_pressed = false;
    }

    bool should_process_delete_press
        = get_key_state(Key::DELETE) == KeyState::PRESSED
          && !is_key_pressed(Key::DELETE);
    bool should_process_delete_release
        = get_key_state(Key::DELETE) == KeyState::RELEASED
          && is_key_pressed(Key::DELETE);

    if (should_process_delete_press) {
        if (currently_highlighted) {
            size_t idx = 0;
            for (size_t i = 0; i < current_molecule->atoms.size(); ++i) {
                if (current_molecule->atoms[i] == currently_highlighted) {
                    idx = i;
                    break;
                }
            }

            bool can_delete = current_molecule->can_delete_atom_at(idx);
            if (can_delete) {
                current_molecule->delete_atom_at(idx);
                current_molecule->calculate_positions();
                currently_highlighted = nullptr;

                current_molecule->generate_texture();
                image_2d->textures.clear();
                image_2d->textures.push_back(current_molecule->image_2d_tex);
            }
            else {
                has_failed_to_delete = true;
            }
        }
        set_key_pressed(Key::DELETE, true);
    }
    if (should_process_delete_release) {

        set_key_pressed(Key::DELETE, false);
    }
}

void App::main_loop() {
    _root_path = PROJECT_DIR;
    glfwSetWindowUserPointer(window(), this);
    set_color({0.1f, 0.1f, 0.1f, 0.5f});
    // Mkdir for temporary files
    std::string command = "mkdir -p " + Molecule::tmp_folder_for_tex_files;
    system(command.c_str());

    auto grid_shader = axolote::gl::Shader::create(
        get_path("resources/shaders/grid_base_vertex_shader.glsl"),
        get_path("resources/shaders/grid_base_fragment_shader.glsl")
    );

    auto image_2d_shader = axolote::gl::Shader::create(
        get_path("resources/shaders/image_2d_vertex_shader.glsl"),
        get_path("resources/shaders/image_2d_fragment_shader.glsl")
    );

    // Quad
    // Vertex has the struct {position, color, tex_uv, normal}
    image_2d = std::make_shared<axolote::GMesh>(
        image_2d_vertices, image_2d_indices,
        std::vector<std::shared_ptr<axolote::gl::Texture>>{}
    );
    image_2d->bind_shader(image_2d_shader);

    auto scene = std::make_shared<axolote::Scene>();
    scene->camera.pos = {0.0f, 0.0f, 12.35f};
    scene->camera.speed = 3.0f;
    scene->camera.sensitivity = 10000.0f;
    scene->ambient_light_intensity = 0.6f;

    dir_light = std::make_shared<axolote::DirectionalLight>(
        glm::vec4{1.0f}, true, glm::vec3{-1.0f, -0.5f, -1.0f}
    );

    scene->add_light(dir_light);

    grid = std::make_shared<axolote::utils::Grid>(
        70, 5, true, glm::vec4{1.0f, 0.0f, 0.0f, 1.0f}
    );
    grid->fading_factor = 70.0f;
    grid->bind_shader(grid_shader);
    scene->set_grid(grid);

    set_scene(scene);

    std::strncpy(mol_name, "metano", 100);
    recreate_molecule_by_name(mol_name);

    double last_time = get_time();
    int second_counter = 0;
    double accumulated_frames = 0;
    while (!should_close()) {
        clear();

        double current_time = get_time();
        double dt = current_time - last_time;
        last_time = current_time;

        if (current_time - second_counter >= 5.0) {
            second_counter = current_time;
            axolote::debug("FPS: %.1lf", accumulated_frames / 5.0);
            accumulated_frames = 0;
        }
        else {
            ++accumulated_frames;
        }

        poll_events();
        if (!ImGui::IsAnyItemActive())
            process_input(dt);

        update_camera((float)width() / height());
        update(dt);
        render();

        // Draw image 2d of molecule
        {
            auto shader = image_2d->get_shaders()[0];
            shader->activate();
            shader->set_uniform_float(
                "image_2d_aspect_ratio", (float)width() / height()
            );
            image_2d->draw();
        }

        im_gui_operations();

        flush();
    }
}

void App::recreate_molecule_by_name(const char *mol_name) {
    auto new_scene = std::make_shared<axolote::Scene>();
    new_scene->camera = current_scene()->camera;
    new_scene->ambient_light_intensity
        = current_scene()->ambient_light_intensity;

    current_molecule = std::make_shared<Molecule>();
    auto parsed_mol = parser::parse(mol_name);
    auto parsed_mol_processed = parser::Molecule1_from_Molecule(parsed_mol);

    current_molecule->setup(parsed_mol_processed);

    new_scene->add_drawable(current_molecule);
    new_scene->add_light(dir_light);
    new_scene->set_grid(grid);
    set_scene(new_scene);

    image_2d->textures.clear();
    image_2d->textures.push_back(current_molecule->image_2d_tex);
}

void App::im_gui_operations() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Set Frame size for ImGui
    ImGui::SetNextWindowSize(ImVec2(280, 100), ImGuiCond_FirstUseEver);
    ImGui::Begin("Nome da molécula");

    static const char *compounds[]{
        "", "Frangonona", "Metanfetamina", "Alcool Etilico", "Aroma de Canela"
    };
    static int current_compound = 0;
    if (ImGui::Combo(
            "Composto", &current_compound, compounds, IM_ARRAYSIZE(compounds)
        )) {
        std::unordered_map<std::string, std::string> compound_map{
            {"Frangonona", "2,6-dietil-3,5-dimetil-ciclohexanona"},
            {"Metanfetamina", "N-metil-1-fenil-propan-2-amina"},
            {"Alcool Etilico", "etanol"},
            {"Aroma de Canela", "3-fenil-prop-2-enal"}
        };
        if (current_compound != 0) {
            char *new_mol_name
                = (char *)compound_map[compounds[current_compound]].c_str();
            std::strncpy(mol_name, new_mol_name, 100);
        }
    }

    ImGui::InputText("Nome", mol_name, 100);
    if (!ImGui::IsPopupOpen("Falha ao deletar")) {
        if (ImGui::Button("Gerar")) {
            recreate_molecule_by_name(mol_name);
        }
        else if (ImGui::IsKeyPressed(ImGuiKey_Enter) && ImGui::IsWindowFocused()
                 && !ImGui::IsAnyItemActive()) {
            recreate_molecule_by_name(mol_name);
        }
    }

    if (has_failed_to_delete) {
        ImGui::OpenPopup("Falha ao deletar");
    }
    if (ImGui::BeginPopupModal(
            "Falha ao deletar", NULL, ImGuiWindowFlags_AlwaysAutoResize
        )) {
        ImGui::Text("Não é possível deletar este átomo.");
        if (ImGui::Button("OK") || ImGui::IsKeyPressed(ImGuiKey_Enter)) {
            has_failed_to_delete = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
