#pragma once

#include "axolote/window.hpp"

class App : public axolote::Window {
public:
    void process_input(double delta_t = 1.0f);
    void main_loop();

    float lat = 0.0f;
    float lon = 0.0f;
    float radius = 10.0f;
};
