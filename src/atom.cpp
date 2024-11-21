#include <glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>

#include "atom.hpp"
#include "utils.hpp"

std::shared_ptr<axolote::GModel> Atom::_gmodel = nullptr;
std::shared_ptr<axolote::gl::Shader> Atom::_shader = nullptr;
Atom::Atom() :
  Atom(glm::vec4{1.0f}) {
}

Atom::Atom(glm::vec4 color) :
  color{color} {
    if (_gmodel == nullptr) {
        _gmodel = std::make_shared<axolote::GModel>(
            myget_path("resources/models/sphere.obj")
        );
    }
    if (_shader == nullptr) {
        _shader = axolote::gl::Shader::create(
            myget_path("resources/shaders/atom_vertex_shader.glsl"),
            myget_path("resources/shaders/atom_fragment_shader.glsl")
        );
    }

    is_affected_by_lights = false;
    is_transparent = false;
    gmodel = _gmodel;
    bind_shader(_shader);

    Atom::color = color;
}

bool Atom::intersect(
    const glm::vec3 &ray_origin, const glm::vec3 &ray_direction
) {
    glm::vec3 position = get_matrix()[3];
    glm::vec3 oc = ray_origin - glm::vec3(position);
    float a = glm::dot(ray_direction, ray_direction);
    float b = 2.0f * glm::dot(oc, ray_direction);
    float c = glm::dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    return discriminant >= 0;
}

void Atom::draw() {
    auto shaders = get_shaders();
    for (auto &shader : shaders) {
        shader->activate();
        shader->set_uniform_float4(
            "atom_color", color.x, color.y, color.z, color.a
        );
        shader->set_uniform_int("atom_highlight", highlighted);
    }
    axolote::Object3D::draw();
}

void Atom::draw(const glm::mat4 &mat) {
    (void)mat;
    draw();
}
