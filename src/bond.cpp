#include <glm/gtc/matrix_transform.hpp>

#include "bond.hpp"

Bond::Bond(const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b)
    : Line::Line{glm::vec3{0.0f}, glm::vec3{0.0f, 1.0f, 0.0f}, 1.0f, thickness, color},
      a{a},
      b{b} {}

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
        case Type::Singular:
            _drawSingularBond();
            break;
        case Type::Double:
            _drawDoubleBond();
            break;
        case Type::Triple:
            _drawTripleBond();
            break;
        default:
            return;
    }
}

void Bond::_drawSingularBond() {
    // Just draw at current position
    Line::draw();
}
void Bond::_drawDoubleBond() {
    // Save current start and end
    // glm::vec3 original_start = start;
    // glm::vec3 original_end = get_end();

    // TODO: Displace to both sides by half right vector and render with half thickness, then change back to original start-end
}
void Bond::_drawTripleBond() {
    // Save current start and end
    // glm::vec3 original_start = start;
    // glm::vec3 original_end = get_end();

    // TODO: Render three times displacing based on right and up vectors
}
