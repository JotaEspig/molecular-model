#pragma once

#include <memory>

#include "axolote/window.hpp"

#include "molecule.hpp"

class App : public axolote::Window {
public:
    void process_input(double delta_t = 1.0f);
    void add_atom(std::shared_ptr<Atom> atom);
    void main_loop();

    float lat = 0.0f;
    float lon = 0.0f;
    float radius = 10.0f;
    bool mouse_pressed = false;
    std::vector<std::shared_ptr<Atom>> atoms;

    std::shared_ptr<Atom> currently_highlighted = nullptr;
};
