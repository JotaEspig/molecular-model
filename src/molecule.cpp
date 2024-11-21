#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <openbabel/bond.h>
#include <openbabel/builder.h>
#include <openbabel/forcefield.h>
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <openbabel/obmolecformat.h>

#include "molecule.hpp"

const std::unordered_map<int, int> atomic_num_to_atomic_radius
    = {{1, 25}, {6, 70}, {7, 65}, {8, 60}};
const int max_atomic_radius = 70;
const int min_atomic_radius = 25;

float normalize_atomic_radius(int atomic_radius) {
    float radius = static_cast<float>(atomic_radius - min_atomic_radius)
                   / static_cast<float>(max_atomic_radius - min_atomic_radius);
    // std::cout << radius << std::endl;
    return radius;
}

Molecule::Molecule() :
  Molecule{glm::vec3{0.0f}} {
}

Molecule::Molecule(const glm::vec3 &center) :
  center{center} {
}

void Molecule::setup(parser::Molecule1 &parsed_mol_processed) {
    for (auto atomic_num : parsed_mol_processed.atoms) {
        add_atom(atomic_num);
    }
    for (auto bond : parsed_mol_processed.bonds) {
        add_bond(bond.i, bond.j, static_cast<Bond::Type>(bond.k));
    }

    calculate_positions();
}

std::shared_ptr<Atom> Molecule::add_atom(int atomic_num) {
    if (atomic_num == 6) {
        return add_carbon();
    }
    else if (atomic_num == 1) {
        return add_hydrogen();
    }
    else if (atomic_num == 7) {
        return add_nitrogen();
    }
    else if (atomic_num == 8) {
        return add_oxygen();
    }
    return nullptr;
}

std::shared_ptr<Atom> Molecule::add_carbon() {
    const float carbon_radius
        = normalize_atomic_radius(atomic_num_to_atomic_radius.at(6));
    auto carbon = std::make_shared<Atom>(glm::vec4{0.3f, 0.3f, 0.3f, 1.0f});
    carbon->radius = carbon_radius;
    carbon->is_affected_by_lights = true;
    atoms.push_back(carbon);

    auto ob_carbon = openbabel_obj.NewAtom();
    ob_carbon->SetAtomicNum(6);

    return carbon;
}

std::shared_ptr<Atom> Molecule::add_hydrogen() {
    const float hydrogen_radius
        = normalize_atomic_radius(atomic_num_to_atomic_radius.at(1)) + 0.5;
    auto hydrogen = std::make_shared<Atom>(glm::vec4{0.4f, 0.8f, 1.0f, 1.0f});
    hydrogen->radius = hydrogen_radius;
    hydrogen->is_affected_by_lights = true;
    atoms.push_back(hydrogen);

    auto ob_hydrogen = openbabel_obj.NewAtom();
    ob_hydrogen->SetAtomicNum(1);
    openbabel_obj.SetHydrogensAdded(true);

    return hydrogen;
}

std::shared_ptr<Atom> Molecule::add_nitrogen() {
    const float nitrogen_radius
        = normalize_atomic_radius(atomic_num_to_atomic_radius.at(7));
    auto nitrogen = std::make_shared<Atom>(glm::vec4{0.0f, 0.0f, 1.0f, 1.0f});
    nitrogen->radius = nitrogen_radius;
    nitrogen->is_affected_by_lights = true;
    atoms.push_back(nitrogen);

    auto ob_nitrogen = openbabel_obj.NewAtom();
    ob_nitrogen->SetAtomicNum(7);

    return nitrogen;
}

std::shared_ptr<Atom> Molecule::add_oxygen() {
    const float oxygen_radius
        = normalize_atomic_radius(atomic_num_to_atomic_radius.at(8));
    auto oxygen = std::make_shared<Atom>(glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});
    oxygen->radius = oxygen_radius;
    oxygen->is_affected_by_lights = true;
    atoms.push_back(oxygen);

    auto ob_oxygen = openbabel_obj.NewAtom();
    ob_oxygen->SetAtomicNum(8);

    return oxygen;
}

std::shared_ptr<Bond> Molecule::add_bond(
    const std::size_t a_idx, const std::size_t b_idx, const Bond::Type type
) {
    auto a = atoms[a_idx];
    auto b = atoms[b_idx];
    auto bond = std::make_shared<Bond>(a, b);
    bond->set_type(type);
    bond->is_affected_by_lights = true;
    bonds.push_back(bond);

    if (!openbabel_obj.AddBond(a_idx + 1, b_idx + 1, static_cast<int>(type))) {
        std::cerr << "Error: Could not add bond!" << std::endl;
    }

    return bond;
}

void Molecule::calculate_positions() {
    // Pre builds the molecule
    // NECESSARY to calculate positions
    // Otherwise, the force field won't work, because if you don't build the
    // molecule the atoms will be at the same position (0, 0, 0)
    OpenBabel::OBBuilder builder;
    builder.Build(openbabel_obj);

    auto forcefield = OpenBabel::OBForceField::FindForceField("GAFF");
    if (!forcefield) {
        std::cerr << "Error: force field not found!" << std::endl;
        return;
    }

    forcefield->SetLogLevel(OBFF_LOGLVL_NONE);
    forcefield->SetLogFile(&std::cout);

    if (!forcefield->Setup(openbabel_obj)) {
        std::cerr << "Error: Could not set up force field!" << std::endl;
        return;
    }
    forcefield->ConjugateGradients(1000, 1.0e-6);
    if (!forcefield->GetCoordinates(openbabel_obj)) {
        std::cerr << "Error: Could not get coordinates!" << std::endl;
        return;
    }

    std::size_t num_atoms = openbabel_obj.NumAtoms();
    glm::vec3 mean_center{0.0f};
    for (std::size_t i = 0; i < num_atoms; ++i) {
        auto atom = openbabel_obj.GetAtom(i + 1);
        auto pos = atom->GetVector();
        glm::vec3 position{pos.GetX(), pos.GetY(), pos.GetZ()};
        position *= 2;
        position += center;

        glm::mat4 mat = glm::translate(glm::mat4{1.0f}, position);
        mean_center += glm::vec3{position};
        atoms[i]->set_matrix(mat);
    }
    mean_center /= atoms.size();

    // Center the molecule at the 0, 0, 0
    for (std::size_t i = 0; i < num_atoms; ++i) {
        auto &atom = atoms[i];
        auto ob_atom = openbabel_obj.GetAtom(i + 1);
        glm::mat4 mat = atom->get_matrix();
        mat = glm::translate(mat, -mean_center);
        mat = glm::scale(
            mat,
            glm::vec3{
                atom->radius
                /*ob_atom->GetAtomicNum() == 1 ? 0.6f : 1.0f*/
            }
        );
        atom->set_matrix(mat);
    }
}

bool Molecule::can_delete_atom_at(const std::size_t idx) const {
    auto atom = openbabel_obj.GetAtom(idx + 1);
    if (atom->GetAtomicNum() == 1) {
        return true;
    }
    // Verifies if the atoms has 2 or more bonds to others non-hydrogen
    // atoms
    std::size_t counter = 0;
    OpenBabel::OBBondIterator bond_it;
    for (auto bond = atom->BeginBond(bond_it); bond;
         bond = atom->NextBond(bond_it)) {
        if (counter >= 2) {
            break;
        }
        auto other_atom = bond->GetNbrAtom(atom);
        if (other_atom->GetAtomicNum() != 1) {
            ++counter;
        }
    }
    return counter < 2;
}

bool Molecule::delete_atom_at(const std::size_t idx) {
    if (!can_delete_atom_at(idx)) {
        return false;
    }

    auto ob_atom = openbabel_obj.GetAtom(idx + 1);
    if (ob_atom->GetAtomicNum() == 1) {
        for (std::size_t i = 0; i < bonds.size(); ++i) {
            auto atom = atoms[idx];
            auto bond = bonds[i];
            if (bond->a() == atom || bond->b() == atom) {
                auto ob_bond = openbabel_obj.GetBond(i);
                openbabel_obj.DeleteBond(ob_bond);
                bonds.erase(bonds.begin() + i);
                break;
            }
        }
        openbabel_obj.DeleteAtom(ob_atom);
        atoms.erase(atoms.begin() + idx);
        return true;
    }

    // Delete all bonds and hydrogen atoms attached to the atom
    std::vector<OpenBabel::OBAtom *> to_delete_atoms;
    std::vector<OpenBabel::OBBond *> to_delete_bonds;
    OpenBabel::OBBondIterator bond_it;
    for (auto bond = ob_atom->BeginBond(bond_it); bond;
         bond = ob_atom->NextBond(bond_it)) {

        auto other_ob_atom = bond->GetNbrAtom(ob_atom);
        to_delete_bonds.push_back(bond);
        if (other_ob_atom->GetAtomicNum() == 1) {
            to_delete_atoms.push_back(other_ob_atom);
        }
    }
    to_delete_atoms.push_back(ob_atom);

    for (auto ob_bond : to_delete_bonds) {
        bonds.erase(bonds.begin() + ob_bond->GetIdx());
        openbabel_obj.DeleteBond(ob_bond);
    }
    for (auto ob_atom : to_delete_atoms) {
        atoms.erase(atoms.begin() + ob_atom->GetIdx() - 1);
        openbabel_obj.DeleteAtom(ob_atom);
    }

    return true;
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
