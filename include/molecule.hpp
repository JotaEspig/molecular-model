#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "atom.hpp"
#include "bond.hpp"

class Molecule : public axolote::Drawable {
public:
    std::vector<std::shared_ptr<Atom>> atoms;
    std::vector<std::shared_ptr<Bond>> bonds;

    Molecule();

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
        const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b,
        Bond::Type type
    );

    void bind_shader(std::shared_ptr<axolote::gl::Shader> shader) override;
    std::vector<std::shared_ptr<axolote::gl::Shader>>
    get_shaders() const override;
    void update(double dt) override;
    void draw() override;
    void draw(const glm::mat4 &mat) override;
};
