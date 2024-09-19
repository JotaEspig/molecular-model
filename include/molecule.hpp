#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "atom.hpp"
#include "bond.hpp"

class Molecule : public axolote::Drawable {
public:
    /// @brief List of pairs [atom, model_mat]
    std::vector<std::pair<std::shared_ptr<Atom>, glm::mat4>> atoms;

    /// @brief List of bonds
    std::vector<std::shared_ptr<Bond>> bonds;

    /// @brief Molecule's center position
    glm::vec3 center;

    Molecule();

    Molecule(const glm::vec3 &center);

    /// @brief Adds a carbon to the scene at provided position
    /// @param pos position relative to center
    /// @return added carbon
    std::shared_ptr<Atom> add_carbon(const glm::vec3 &pos = glm::vec3{0.0f});

    /// @brief Add a hydrogen to the scene at provided position
    /// @param pos position relative to center
    /// @return added hydrogen
    std::shared_ptr<Atom> add_hydrogen(const glm::vec3 &pos = glm::vec3{0.0f});

    /// @brief Adds a bond to the scene between the two provided atoms
    /// @param a first atom
    /// @param b second atom
    /// @param type bond type
    /// @return added bond
    std::shared_ptr<Bond> add_bond(
        const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b,
        Bond::Type type = Bond::Type::SINGULAR
    );

    /// @brief Sets molecule rotation, applies to all its atoms
    /// @param rotation rotation matrix
    void set_rotation(const glm::mat4 &rotation);

    void bind_shader(std::shared_ptr<axolote::gl::Shader> shader) override;
    std::vector<std::shared_ptr<axolote::gl::Shader>>
    get_shaders() const override;
    void update(double dt) override;
    void draw() override;
    void draw(const glm::mat4 &mat) override;

private:
    glm::mat4 _rotation = glm::mat4{1.0f};
};

/// @brief creates a methane molecule
/// @param pos center position
/// @param distance distance between hydrogens and carbon (bond length)
/// @return methane molecule
std::shared_ptr<Molecule> create_methane(const glm::vec3 &pos, float distance);