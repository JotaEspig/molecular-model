#include <glm/gtc/matrix_transform.hpp>

#include "bond.hpp"

Bond::Bond(const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b) :
  Line::Line{
      glm::vec3{0.0f}, glm::vec3{0.0f, 1.0f, 0.0f}, 1.0f, thickness, color
  },
  a{a},
  b{b} {
}

void Bond::set_type(Type type) {
    Bond::type = type;
}

Bond::Type Bond::get_type() {
    return type;
}

void Bond::update(double dt) {
    // Set start to atom A's position
    auto mat_a = a->get_matrix();
    glm::vec3 pos = mat_a[3];
    start = pos;

    // Set end to atom B's position
    auto mat_b = b->get_matrix();
    glm::vec3 end = mat_b[3];
    set_end(end);

    // Update line rotation
    Line::update(dt);
}

void Bond::draw() {
    switch (type) {
    case Type::SINGULAR:
        _drawSingularBond();
        break;
    case Type::DOUBLE:
        _drawDoubleBond();
        break;
    case Type::TRIPLE:
        _drawTripleBond();
        break;
    case Type::QUADRUPLE:
        _drawQuadrupleBond();
        break;
    default:
        return;
    }
}

void Bond::_drawSingularBond() {
    // Save original size
    const float original_thickness = Bond::thickness;

    // Just draw at current position with increased size to match other types
    Line::thickness = original_thickness * 2.0f;
    Line::update(0.0);
    Line::draw();

    // Revert thickness
    Line::thickness = original_thickness;
}

void Bond::_drawDoubleBond() {
    // Save current start and end
    glm::vec3 original_start = start;
    glm::vec3 original_end = get_end();

    // Get right vector
    glm::vec3 right = glm::cross(dir_vec, glm::vec3{0.0f, 1.0f, 0.0f});
    if (glm::dot(right, right) == 0.0f) {
        // dir_vec is straight up
        right = glm::cross(dir_vec, glm::vec3{0.0f, 0.0f, -1.0f});
    }
    right = glm::normalize(right);

    // Dispĺace left
    const float displacement = 0.4f;
    glm::vec3 displacement_left = -right * displacement;
    start = original_start + displacement_left;
    set_end(original_end + displacement_left);
    Line::update(0.0f);
    Line::draw();

    // Displace right
    glm::vec3 displacement_right = right * displacement;
    start = original_start + displacement_right;
    set_end(original_end + displacement_right);
    Line::update(0.0f);
    Line::draw();

    // Restore start and end
    start = original_start;
    set_end(original_end);
}

void Bond::_drawTripleBond() {
    // Save current start and end
    glm::vec3 original_start = start;
    glm::vec3 original_end = get_end();

    // Get right and up vector
    glm::vec3 right = glm::cross(dir_vec, glm::vec3{0.0f, 1.0f, 0.0f});
    if (glm::dot(right, right) == 0.0f) {
        // dir_vec is straight up
        right = glm::cross(dir_vec, glm::vec3{0.0f, 0.0f, -1.0f});
    }
    right = glm::normalize(right);
    glm::vec3 up = glm::normalize(glm::cross(right, dir_vec)) * 0.866f;

    // Dispĺace up
    const float displacement = 0.4f;
    glm::vec3 displacement_up = up * displacement;
    start = original_start + displacement_up;
    set_end(original_end + displacement_up);
    Line::update(0.0f);
    Line::draw();

    // Displace bottom left
    glm::vec3 displacement_bot_left = (-up - right) * displacement;
    start = original_start + displacement_bot_left;
    set_end(original_end + displacement_bot_left);
    Line::update(0.0f);
    Line::draw();

    // Displace bottom right
    glm::vec3 displacement_bot_right = (-up + right) * displacement;
    start = original_start + displacement_bot_right;
    set_end(original_end + displacement_bot_right);
    Line::update(0.0f);
    Line::draw();

    // Restore start and end
    start = original_start;
    set_end(original_end);
}

void Bond::_drawQuadrupleBond() {
    // Save current start and end
    glm::vec3 original_start = start;
    glm::vec3 original_end = get_end();

    // Get right and up vector
    glm::vec3 right = glm::cross(dir_vec, glm::vec3{0.0f, 1.0f, 0.0f});
    if (glm::dot(right, right) == 0.0f) {
        // dir_vec is straight up
        right = glm::cross(dir_vec, glm::vec3{0.0f, 0.0f, -1.0f});
    }
    right = glm::normalize(right);
    glm::vec3 up = glm::normalize(glm::cross(right, dir_vec));

    // Displace bottom left
    const float displacement = 0.4f;
    glm::vec3 displacement_bot_left = (-up - right) * displacement;
    start = original_start + displacement_bot_left;
    set_end(original_end + displacement_bot_left);
    Line::update(0.0f);
    Line::draw();

    // Displace bottom right
    glm::vec3 displacement_bot_right = (-up + right) * displacement;
    start = original_start + displacement_bot_right;
    set_end(original_end + displacement_bot_right);
    Line::update(0.0f);
    Line::draw();

    // Dispĺace top left
    glm::vec3 displacement_top_left = (up - right) * displacement;
    start = original_start + displacement_top_left;
    set_end(original_end + displacement_top_left);
    Line::update(0.0f);
    Line::draw();

    // Dispĺace top right
    glm::vec3 displacement_top_right = (up + right) * displacement;
    start = original_start + displacement_top_right;
    set_end(original_end + displacement_top_right);
    Line::update(0.0f);
    Line::draw();

    // Restore start and end
    start = original_start;
    set_end(original_end);
}
