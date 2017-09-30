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
        shaderManager->getActiveShader()->setMat4("projection", getProjectionMatrix());

//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
        //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    }

    GLFWwindow *OpenGLRenderer::getWindow() const {
        return window;
    }

    void OpenGLRenderer::setWindow(GLFWwindow *window) {
        this->window = window;
    }
}


