//
// Created by Gabriel Schneider on 9/27/2017.
//

#include <iostream>
#include <glad/glad.h>
#include "OpenGLRenderer.h"
#include "Exception.h"
#include "WindowManager.h"

void Raven::OpenGLRenderer::setup() {
    std::cout << "Setup" << std::endl;
    if (!gladLoadGL()) {
        throw Raven::Exception("Could not initialize GLAD!");
    }
}

void Raven::OpenGLRenderer::render() {
    std::cout << "Renderer!" << std::endl;
}

GLFWwindow *Raven::OpenGLRenderer::getWindow() const {
    return window;
}

void Raven::OpenGLRenderer::setWindow(GLFWwindow *window) {
    this->window = window;
}
