#pragma once

#include <memory>

#include "axolote/window.hpp"

#include "molecule.hpp"

class App : public axolote::Window {
public:
    void process_input(double delta_t = 1.0f);
    void main_loop();

    float lat = 0.0f;
    float lon = 0.0f;
    float radius = 10.0f;
    bool mouse_pressed = false;
    bool has_failed_to_delete = false;

    char mol_name[100];
    std::shared_ptr<Molecule> current_molecule = nullptr;
    std::shared_ptr<Atom> currently_highlighted = nullptr;
    std::shared_ptr<axolote::utils::Grid> grid;
    std::shared_ptr<axolote::DirectionalLight> dir_light;

    void recreate_molecule_by_name(const char *mol_name);
    void im_gui_operations();
};
