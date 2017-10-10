#version 330 core

in vec3 color;
in vec2 textureCoord;

out vec4 out_Color;

uniform sampler2D tex;

void main() {
    out_Color = texture(tex, textureCoord);// * vec4(color, 1.0f);
}