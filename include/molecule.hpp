#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <openbabel/forcefield.h>
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <openbabel/obmolecformat.h>

#include "atom.hpp"
#include "bond.hpp"

class Molecule : public axolote::Drawable {
public:
    OpenBabel::OBMol openbabel_obj;
    /// @brief List of pairs [atom, model_mat]
    std::vector<std::shared_ptr<Atom>> atoms;
    /// @brief List of bonds
    std::vector<std::shared_ptr<Bond>> bonds;
    /// @brief Molecule's center position
    glm::vec3 center;

    Molecule();

    Molecule(const glm::vec3 &center);

    /// @brief Adds a carbon to the scene
    /// @return added carbon
    std::shared_ptr<Atom> add_carbon();

    /// @brief Add a hydrogen to the scene
    /// @return added hydrogen
    std::shared_ptr<Atom> add_hydrogen();
    /// @brief Add left hydrogens to the scene at provided position
    /// @return added hydrogens
    std::vector<std::shared_ptr<Atom>> add_hydrogens();

    /// @brief Adds a bond to the scene between the two provided atoms
    /// @param a_idx first atom index
    /// @param b_idx second atom index
    /// @param type bond type
    /// @return added bond
    std::shared_ptr<Bond> add_bond(
        const std::size_t a_idx, const std::size_t b_idx,
        const Bond::Type type = Bond::Type::SINGULAR
    );

    /// @brief Calculate atoms positions, should be called after adding all
    /// atoms
    void calculate_positions();

    void bind_shader(std::shared_ptr<axolote::gl::Shader> shader) override;
    std::vector<std::shared_ptr<axolote::gl::Shader>>
    get_shaders() const override;
    void update(double dt) override;
    void draw() override;
    void draw(const glm::mat4 &mat) override;

private:
    glm::mat4 _rotation = glm::mat4{1.0f};
};
