#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

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

void decompose_matrix(const glm::mat4 &m, glm::vec3 &pos, glm::mat4 &rot, glm::vec3 &scale) {
    pos = m[3];

    for(int i = 0; i < 3; i++) {
        scale[i] = glm::length(glm::vec3{m[i]});
    }

    const glm::mat3 rot_matrix(
        glm::vec3{m[0]} / scale[0],
        glm::vec3{m[1]} / scale[1],
        glm::vec3{m[2]} / scale[2]
    );

    rot = glm::toMat4(glm::quat_cast(rot_matrix));
}

Molecule::Molecule() : Molecule{glm::vec3{0.0f}} {}

Molecule::Molecule(const glm::vec3 &center) : center{center} {}

std::shared_ptr<Atom> Molecule::add_carbon(const glm::vec3 &pos) {
    auto carbon = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    carbon->is_affected_by_lights = true;

    // Save relative model matrix
    glm::mat4 mat{1.0f};
    mat = glm::translate(mat, pos);
    atoms.push_back(std::make_pair(carbon, mat));

    // Set initial global model matrix
    mat = glm::translate(mat, center);
    carbon->set_matrix(mat);
    return carbon;
}

std::shared_ptr<Atom> Molecule::add_hydrogen(const glm::vec3 &pos) {
    auto hydrogen = std::make_shared<Atom>(glm::vec4{0.4f, 0.8f, 1.0f, 1.0f});
    hydrogen->is_affected_by_lights = true;

    // Save relative model matrix
    glm::mat4 mat{1.0f};
    mat = glm::translate(mat, pos);
    mat = glm::scale(mat, glm::vec3{0.5f});
    atoms.push_back(std::make_pair(hydrogen, mat));

    // Set initial global model matrix
    mat = glm::translate(mat, center);
    hydrogen->set_matrix(mat);
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

void Molecule::set_rotation(const glm::mat4 &rotation) {
    for (auto &[atom, model_mat] : atoms) {
        glm::vec3 pos;
        glm::mat4 rot;
        glm::vec3 scale;
        decompose_matrix(model_mat, pos, rot, scale);

        glm::mat4 new_mat{1.0f};
        new_mat = glm::translate(new_mat, center);
        new_mat *= rotation;
        new_mat = glm::translate(new_mat, pos);
        new_mat *= rot;
        new_mat = glm::scale(new_mat, scale);

        // glm::mat4 new_mat = rotation;
        // new_mat *= model_mat;

        atom->set_matrix(new_mat);
    }
}


void Molecule::bind_shader(std::shared_ptr<axolote::gl::Shader> shader) {
    (void)shader;
}

std::vector<std::shared_ptr<axolote::gl::Shader>>
Molecule::get_shaders() const {
    std::vector<std::shared_ptr<axolote::gl::Shader>> shaders;
    for (auto &[atom, _] : atoms) {
        auto aux = atom->get_shaders();
        shaders.insert(shaders.end(), aux.begin(), aux.end());
        break;
    }
    for (auto &bond : bonds) {
        auto aux = bond->get_shaders();
        shaders.insert(shaders.end(), aux.begin(), aux.end());
        break;
    }
    return shaders;
}

void Molecule::update(double dt) {
    for (auto &[atom, _] : atoms) {
        atom->update(dt);
    }

    for (auto &bond : bonds) {
        bond->update(dt);
    }
}

void Molecule::draw() {
    for (auto &[atom, _] : atoms) {
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

std::shared_ptr<Molecule> create_methane(const glm::vec3 &pos, float distance) {
    // Create hydrogen atoms
    auto methane = std::make_shared<Molecule>(pos);
    auto carbon = methane->add_carbon();
    for (int i = 0; i < 4; ++i) {
        auto atom_pos = methane_positions[i] * distance;
        auto hydrogen = methane->add_hydrogen(atom_pos);
        methane->add_bond(carbon, hydrogen);
    }

    return methane;
}