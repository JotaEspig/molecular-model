#include <cstdio>
#include <ctime>
#include <memory>
#include <unordered_map>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <cairo/cairo.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <librsvg/rsvg.h>
#include <openbabel/bond.h>
#include <openbabel/builder.h>
#include <openbabel/forcefield.h>
#include <openbabel/mol.h>
#include <openbabel/obconversion.h>
#include <openbabel/obmolecformat.h>
#include <openbabel/op.h>

#define DEBUG // Enables debug function
#include "axolote/utils.hpp"
#include "molecule.hpp"

#define UPSCALING_FACTOR 4

std::string Molecule::tmp_folder_for_tex_files = "/tmp/molecular_model/";

const std::unordered_map<int, int> atomic_num_to_atomic_radius
    = {{1, 25}, {6, 70}, {7, 65}, {8, 60}};
const int max_atomic_radius = 70;
const int min_atomic_radius = 25;
float normalize_atomic_radius(int atomic_radius) {
    float radius = static_cast<float>(atomic_radius - min_atomic_radius)
                   / static_cast<float>(max_atomic_radius - min_atomic_radius);
    return radius;
}

// Function to convert SVG to PNG using Cairo and librsvg
void convert_svg_to_png(
    const std::string &svg_content, const std::string &png_file
) {
    RsvgHandle *handle = rsvg_handle_new_from_data(
        reinterpret_cast<const guint8 *>(svg_content.c_str()),
        svg_content.size(), NULL
    );
    if (!handle) {
        axolote::debug("Failed to create RsvgHandle from SVG content.");
        return;
    }

    double width, height;
    rsvg_handle_get_intrinsic_size_in_pixels(handle, &width, &height);

    // Improves image quality
    width *= UPSCALING_FACTOR;
    height *= UPSCALING_FACTOR;

    cairo_surface_t *surface
        = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t *cr = cairo_create(surface);

    GError *error = nullptr;
    RsvgRectangle viewport = {0, 0, width, height};
    if (!rsvg_handle_render_document(handle, cr, &viewport, &error))
        axolote::debug("Failed to render SVG to Cairo surface.");

    if (error) {
        axolote::debug("Error rendering SVG: {}", error->message);
        g_error_free(error);
    }

    cairo_status_t status
        = cairo_surface_write_to_png(surface, png_file.c_str());
    if (status == CAIRO_STATUS_SUCCESS) {
        axolote::debug("PNG file created at %s", png_file.c_str());
    }
    else {
        axolote::debug("Failed to write PNG file.");
    }

    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    g_object_unref(handle);
}

Molecule::Molecule() :
  Molecule{glm::vec3{0.0f}} {
    generate_filename();
}

Molecule::Molecule(const glm::vec3 &center) :
  center{center} {
    generate_filename();
}

void Molecule::setup(parser::Molecule1 &parsed_mol_processed) {
    for (auto atomic_num : parsed_mol_processed.atoms) {
        add_atom(atomic_num);
    }
    for (auto bond : parsed_mol_processed.bonds) {
        add_bond(bond.i, bond.j, static_cast<Bond::Type>(bond.k));
    }

    calculate_positions();
    generate_texture();
}

void Molecule::generate_texture() {
    // Create a 2D representation of the molecule
    OpenBabel::OBMol obmol = openbabel_obj;
    obmol.DeleteHydrogens();

    OpenBabel::OBConversion conv;
    OpenBabel::OBOp::FindType("gen2d")->Do(&obmol);
    if (!conv.SetOutFormat("svg"))
        axolote::debug("Failed to set output format for molecule");

    std::string svg = conv.WriteString(&obmol);
    if (svg.empty())
        axolote::debug("Failed to convert molecule to SVG");

    convert_svg_to_png(svg, image_2d_tex_filename);

    image_2d_tex = axolote::gl::Texture::create(
        image_2d_tex_filename, "diffure", (GLuint)0
    );
}

void Molecule::generate_filename() {
    std::time_t t = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, 80, "%Y%m%d%H%M%S", std::localtime(&t));
    image_2d_tex_filename
        = tmp_folder_for_tex_files + std::string{buffer} + ".png";
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
        glm::mat4 mat = atom->get_matrix();
        mat = glm::translate(mat, -mean_center);
        mat = glm::scale(mat, glm::vec3{atom->radius});
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
