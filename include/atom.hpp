#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "axolote/gl/shader.hpp"
#include "axolote/gmodel.hpp"
#include "axolote/object3d.hpp"

/**
 * @brief Atom class
 * @author João Vitor Espig (jotaespig@gmail.com)
 **/
class Atom : public axolote::Object3D {
public:
    float radius = 1.0f;
    glm::vec4 color{1.0f};
    bool highlighted = false;

    /**
     * @brief Constructor
     **/
    Atom();
    /**
     * @brief Constructor
     **/
    Atom(glm::vec4 color);

    bool intersect(const glm::vec3 &ray_origin, const glm::vec3 &ray_direction);
    void draw() override;
    void draw(const glm::mat4 &mat) override;

private:
    static std::shared_ptr<axolote::GModel> _gmodel;
    static std::shared_ptr<axolote::gl::Shader> _shader;
};
