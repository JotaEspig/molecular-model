#pragma once

#include <memory>

#include "axolote/window.hpp"

#include "bond.hpp"

class App : public axolote::Window {
public:
    void process_input(double delta_t = 1.0f);
    void main_loop();

    /// @brief Adds a carbon to the scene at provided position
    /// @param pos position
    /// @return added carbon
    std::shared_ptr<Atom> add_carbon(const glm::vec3 &pos);

    /// @brief Add a hydrogen to the scene at provided position
    /// @param pos position
    /// @return added hydrogen
    std::shared_ptr<Atom> add_hydrogen(const glm::vec3 &pos);

    /// @brief Adds a bond to the scene between the two provided atoms
    /// @param a first atom
    /// @param b second atom
    /// @param type bond type
    /// @return added bond
    std::shared_ptr<Bond> add_bond(
        const std::shared_ptr<Atom> &a,
        const std::shared_ptr<Atom> &b,
        Bond::Type type
    );

    std::shared_ptr<axolote::gl::Shader> object_shader;
    float lat = 0.0f;
    float lon = 0.0f;
    float radius = 10.0f;

};