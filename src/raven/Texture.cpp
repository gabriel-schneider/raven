//
// Created by Gabriel Schneider on 9/30/2017.
//

#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include "Texture.h"
#include "Exception.h"

Raven::Texture::Texture() {
    glGenTextures(1, &id);
}

bool Raven::Texture::load(std::string filename) {
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    if (data) {
        bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        unbind();
        return true;
    }
    stbi_image_free(data);
    throw Exception("Could not load texture!");
}

void Raven::Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void Raven::Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
