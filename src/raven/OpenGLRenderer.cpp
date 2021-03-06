//
// Created by Gabriel Schneider on 9/27/2017.
//

#include <iostream>
#include <glad/glad.h>
#include "Application.h"
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
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ShaderManager* shaderManager = getApplication()->getShaderManager();
        shaderManager->getActiveShader()->setUniform("projection", getProjectionMatrix());
        shaderManager->getActiveShader()->setUniform("view", camera->getViewMatrix());
    }

}


