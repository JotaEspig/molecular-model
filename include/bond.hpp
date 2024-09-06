#pragma once

#include <memory>

#include "axolote/utils/line.hpp"

#include "atom.hpp"

/// @brief Class representing a bond between two atoms
class Bond : public axolote::utils::Line {
public:
    /// @brief Bond type
    enum class Type {
        /// @brief singular bond
        Singular,

        /// @brief double bond
        Double,

        /// @brief triple bond
        Triple,

        /// @brief quadruple bond
        Quadruple,
    };

    /// @brief Default constructor
    Bond() = default;

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

    void update(double dt) override;
    void draw() override;

private:
    void _drawSingularBond();
    void _drawDoubleBond();
    void _drawTripleBond();
    void _drawQuadrupleBond();

    /// @brief pointer to first atom
    std::shared_ptr<Atom> a;

    /// @brief pointer to seond atom
    std::shared_ptr<Atom> b;

    /// @brief Bond type
    Type type = Type::Singular;

    /// @brief Default bond thickness
    static constexpr float thickness = 0.15f;

    /// @brief Default bond color
    static constexpr glm::vec4 color = glm::vec4{1.0f};
};