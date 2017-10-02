//
// Created by Gabriel Schneider on 9/27/2017.
//

#include <iostream>
#include <glad/glad.h>
#include "OpenGLRenderer.h"
#include "Exception.h"
#include "WindowManager.h"
#include "ShaderManager.h"
#include "Shader.h"

namespace Raven {
    void OpenGLRenderer::setup() {
        if (!gladLoadGL()) {
            throw Raven::Exception("Could not initialize GLAD!");
        }
    }

    void OpenGLRenderer::render() {
        ShaderManager* shaderManager = (ShaderManager*) serviceLocator->get("shaderManager");
        shaderManager->getActiveShader()->setUniform("projection", getProjectionMatrix());
    }

    GLFWwindow *OpenGLRenderer::getWindow() const {
        return window;
    }

    void OpenGLRenderer::setWindow(GLFWwindow *window) {
        this->window = window;
    }
}


