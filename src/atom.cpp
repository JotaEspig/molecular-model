#include <glm/gtc/matrix_transform.hpp>

#include "atom.hpp"
#include "utils.hpp"

std::shared_ptr<axolote::GModel> Atom::_gmodel = nullptr;
std::shared_ptr<axolote::gl::Shader> Atom::_shader = nullptr;

Atom::Atom() :
  Atom(glm::vec4{1.0f}) {
}

Atom::Atom(glm::vec4 color, float scale) :
  color{color} {
    if (_gmodel == nullptr) {
        _gmodel = std::make_shared<axolote::GModel>(
            myget_path("resources/models/sphere.obj")
        );
    }
    if (_shader == nullptr) {
        _shader = axolote::gl::Shader::create(
            myget_path("resources/shaders/atom_vertex_shader.glsl"),
            myget_path("resources/shaders/object3d_base_fragment_shader.glsl")
        );
    }

    is_affected_by_lights = false;
    is_transparent = false;
    gmodel = _gmodel;
    bind_shader(_shader);
    set_matrix(glm::scale(glm::mat4{1.0f}, glm::vec3{scale}));

    Atom::color = color;
}

void Atom::draw() {
    auto shaders = get_shaders();
    for (auto &shader : shaders) {
        shader->activate();
        shader->set_uniform_float4(
            "atom_color", color.x, color.y, color.z, color.a
        );
    }
    axolote::Object3D::draw();
}

void Atom::draw(const glm::mat4 &mat) {
    (void)mat;
    draw();
}
