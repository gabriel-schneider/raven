#version 330 core

layout(location = 0) in vec3 in_Position;
layout(location = 1) in vec3 in_Color;
layout(location = 2) in vec2 in_TextureCoord;

out vec3 color;
out vec2 textureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(in_Position, 1.0f);
    color = in_Color;
    textureCoord = vec2(in_TextureCoord.x, in_TextureCoord.y);
}