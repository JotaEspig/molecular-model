#version 330 core
layout(location = 0) in vec3 axolote_aPos;
layout(location = 1) in vec4 axolote_aColor;
layout(location = 2) in vec2 axolote_aTex;

out vec4 axolote_color;
out vec2 axolote_tex_coord;
out vec3 axolote_current_pos;

uniform float image_2d_aspect_ratio;

void main() {
    axolote_tex_coord = axolote_aTex;
    axolote_color = axolote_aColor;
    vec3 scaled_pos = axolote_aPos;
    if (image_2d_aspect_ratio > 1.0f) {
        scaled_pos.x /= image_2d_aspect_ratio;
    }
    else if (image_2d_aspect_ratio < 1.0f) {
        scaled_pos.y *= image_2d_aspect_ratio;
    }

    // scale
    scaled_pos *= 0.25f;
    // translate to bottom right corner
    if (image_2d_aspect_ratio > 1.0f) {
        scaled_pos.x += 0.75f;
        scaled_pos.y -= 0.75f;
    }
    else if (image_2d_aspect_ratio < 1.0f) {
        scaled_pos.x += 0.75f;
        scaled_pos.y -= 0.75f;
    }
    else {
        scaled_pos.x += 0.75f;
        scaled_pos.y -= 0.75f;
    }

    gl_Position = vec4(scaled_pos, 1.0f);
}
