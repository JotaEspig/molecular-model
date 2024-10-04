#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <openbabel/forcefield.h>
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <openbabel/obmolecformat.h>

#include "molecule.hpp"

Molecule::Molecule() :
  Molecule{glm::vec3{0.0f}} {
}

Molecule::Molecule(const glm::vec3 &center) :
  center{center} {
}

std::shared_ptr<Atom> Molecule::add_carbon() {
    const float carbon_radius = 1.0f;
    auto carbon = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    carbon->radius = carbon_radius;
    carbon->is_affected_by_lights = true;
    atoms.push_back(carbon);

    auto ob_carbon = openbabel_obj.NewAtom();
    ob_carbon->SetAtomicNum(6);

    return carbon;
}

std::shared_ptr<Atom> Molecule::add_hydrogen() {
    const float hydrogen_radius = 0.5f;
    auto hydrogen = std::make_shared<Atom>(glm::vec4{0.4f, 0.8f, 1.0f, 1.0f});
    hydrogen->radius = hydrogen_radius;
    hydrogen->is_affected_by_lights = true;
    atoms.push_back(hydrogen);

    auto ob_hydrogen = openbabel_obj.NewAtom();
    ob_hydrogen->SetAtomicNum(1);

    return hydrogen;
}

std::shared_ptr<Bond> Molecule::add_bond(
    const std::size_t a_idx, const std::size_t b_idx, Bond::Type type
) {
    auto a = atoms[a_idx];
    auto b = atoms[b_idx];
    auto bond = std::make_shared<Bond>(a, b);
    bond->set_type(type);
    bond->is_affected_by_lights = true;
    bonds.push_back(bond);

    openbabel_obj.AddBond(a_idx + 1, b_idx + 1, static_cast<int>(type));

    return bond;
}

void Molecule::calculate_positions() {
    auto forcefield = OpenBabel::OBForceField::FindForceField("GAFF");
    if (!forcefield) {
        std::cerr << "Error: force field not found!" << std::endl;
        return;
    }
    forcefield->SetLogLevel(OBFF_LOGLVL_HIGH);
    if (!forcefield->Setup(openbabel_obj)) {
        std::cerr << "Error: Could not set up force field!" << std::endl;
        return;
    }
    forcefield->ConjugateGradients(1000, 1.0e-6);
    forcefield->GetCoordinates(openbabel_obj);
    std::size_t num_atoms = openbabel_obj.NumAtoms();
    for (std::size_t i = 0; i < num_atoms; ++i) {
        auto atom = openbabel_obj.GetAtom(i + 1);
        auto pos = atom->GetVector();
        double x = pos.GetX();
        double y = pos.GetY();
        double z = pos.GetZ();
        std::cout << "Atom " << i << " index " << atom->GetIndex() << " at ("
                  << x << ", " << y << ", " << z << ")" << std::endl;
        glm::mat4 mat{1.0f};
        glm::vec3 position{x, y, z};
        position *= 2;
        position += center;
        mat = glm::translate(mat, position);
        mat = glm::scale(
            mat, glm::vec3{atom->GetAtomicNum() == 1 ? 0.5f : 1.0f}
        );
        atoms[i]->set_matrix(mat);
    }
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
