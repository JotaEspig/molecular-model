#pragma once

#include "axolote/object3d.hpp"

/// @brief Class representing a bond between two atoms
class Bond : public axolote::Object3D {
    /// @brief Bond type
    enum class Type {
        /// @brief singular bond
        Singular,

        /// @brief double bond
        Double,

        /// @brief triple bond
        Triple,
    };
};