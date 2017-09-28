//
// Created by Gabriel Schneider on 9/27/2017.
//

#include <iostream>
#include <glad/glad.h>
#include "OpenGLRenderer.h"
#include "Exception.h"
#include "WindowManager.h"

namespace Raven {
    void OpenGLRenderer::setup() {
        if (!gladLoadGL()) {
            throw Raven::Exception("Could not initialize GLAD!");
        }
    }

    void OpenGLRenderer::render() {
        std::cout << "Renderer!" << std::endl;
    }

    GLFWwindow *OpenGLRenderer::getWindow() const {
        return window;
    }

    void OpenGLRenderer::setWindow(GLFWwindow *window) {
        this->window = window;
    }
}


