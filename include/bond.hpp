#pragma once

#include <memory>

#include "axolote/gl/shader.hpp"
#include "axolote/utils/line.hpp"

#include "atom.hpp"

/// @brief Class representing a bond between two atoms
class Bond : public axolote::utils::Line {
public:
    /// @brief Bond type
    enum class Type {
        /// @brief singular bond
        SINGULAR = 1,

        /// @brief double bond
        DOUBLE = 2,

        /// @brief triple bond
        TRIPLE = 3,

        /// @brief quadruple bond
        QUADRUPLE = 4,
    };

    /// @brief Default constructor
    Bond();

    /// @brief Constructor with atoms linked by this bond
    /// @param a first atom
    /// @param b second atom
    Bond(const std::shared_ptr<Atom> &a, const std::shared_ptr<Atom> &b);

    /// @brief Sets new bond type
    /// @param type bond type
    void set_type(Type type);

    /// @brief Returns bond type
    /// @return current bond type
    Type get_type();

    /// @brief getter for first atom
    /// @return first atom
    std::shared_ptr<Atom> a();
    /// @brief getter for second atom
    /// @return second atom
    std::shared_ptr<Atom> b();

    void update(double dt) override;
    void draw() override;

private:
    void _drawSingularBond();
    void _drawDoubleBond();
    void _drawTripleBond();
    void _drawQuadrupleBond();

    /// @brief pointer to first atom
    std::shared_ptr<Atom> _a;

    /// @brief pointer to seond atom
    std::shared_ptr<Atom> _b;

    /// @brief Bond type
    Type type = Type::SINGULAR;

    /// @brief Default bond thickness
    static constexpr float thickness = 0.3f;

    /// @brief Default bond color
    static constexpr glm::vec4 color = glm::vec4{1.0f};

    /// @brief Shader used to render bonds
    static std::shared_ptr<axolote::gl::Shader> _bond_shader;
};
