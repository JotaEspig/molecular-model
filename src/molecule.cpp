#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "molecule.hpp"

// Positions for the 4 points of a tetrahederon
// https://en.wikipedia.org/wiki/Tetrahedron
const float root2 = glm::sqrt(2.0f);
const float root8 = glm::sqrt(8.0f);
const float inv_root3 = 1.0f / glm::sqrt(3.0f);
const float third = 1.0f / 3.0f;

const glm::vec3 methane_positions[4] = {
    {root8 * third, -third, 0.0f},
    {-root2 * third, -third, root2 * inv_root3},
    {-root2 * third, -third, -root2 * inv_root3},
    {0.0f, 1.0f, 0.0f}
};

Molecule::Molecule() {
}

std::shared_ptr<Atom> Molecule::add_carbon(const glm::vec3 &pos) {
    auto carbon = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    carbon->is_affected_by_lights = true;
    carbon->set_matrix(glm::translate(glm::mat4{1.0f}, pos));
    atoms.push_back(carbon);
    return carbon;
}

std::shared_ptr<Atom> Molecule::add_hydrogen(const glm::vec3 &pos) {
    auto hydrogen = std::make_shared<Atom>(glm::vec4{0.4f, 0.8f, 1.0f, 1.0f});
    hydrogen->is_affected_by_lights = true;

    glm::mat4 mat{1.0f};
    mat = glm::translate(mat, pos);
    mat = glm::scale(mat, glm::vec3{0.5f});
    hydrogen->set_matrix(mat);
    atoms.push_back(hydrogen);
    return hydrogen;
}

std::shared_ptr<Bond> Molecule::add_bond(
    const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b,
    Bond::Type type
) {
    auto bond = std::make_shared<Bond>(a, b);
    bond->set_type(type);
    bond->is_affected_by_lights = true;
    bonds.push_back(bond);
    return bond;
}

void Molecule::bind_shader(std::shared_ptr<axolote::gl::Shader> shader) {
    (void)shader;
}

std::vector<std::shared_ptr<axolote::gl::Shader>>
Molecule::get_shaders() const {
    std::vector<std::shared_ptr<axolote::gl::Shader>> shaders;
    for (auto &atom : atoms) {
        auto aux = atom->get_shaders();
        shaders.insert(shaders.end(), aux.begin(), aux.end());
    }
    for (auto &bond : bonds) {
        auto aux = bond->get_shaders();
        shaders.insert(shaders.end(), aux.begin(), aux.end());
    }
    return shaders;
}

void Molecule::update(double dt) {
    for (auto &atom : atoms) {
        atom->update(dt);
    }

    for (auto &bond : bonds) {
        bond->update(dt);
    }
}

void Molecule::draw() {
    for (auto &atom : atoms) {
        atom->draw();
    }

    for (auto &bond : bonds) {
        bond->draw();
    }
}

void Molecule::draw(const glm::mat4 &mat) {
    (void)mat;
    draw();
}

std::shared_ptr<Molecule> create_methane(
    const glm::vec3 &pos, float distance,
    const glm::mat3 &rotation
) {
    // Model matrix based on parameters
    glm::mat3 model{1.0f};
    model *= rotation;
    model *= (glm::mat3)glm::scale(glm::mat4{1.0f}, glm::vec3{distance});

    // Create hydrogen atoms
    auto methane = std::make_shared<Molecule>();
    auto carbon = methane->add_carbon(pos);
    for (int i = 0; i < 4; ++i) {
        auto atom_pos = pos + model * methane_positions[i];
        auto hydrogen = methane->add_hydrogen(atom_pos);
        methane->add_bond(carbon, hydrogen);
    }

    return methane;
}