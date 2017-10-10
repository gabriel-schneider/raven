//
// Created by Gabriel Schneider on 9/27/2017.
//

#include <iostream>
#include "GLFW/glfw3.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "Application.h"
#include "Renderer.h"
#include "OpenGLRenderer.h"
#include "Exception.h"
#include "SceneManager.h"


namespace Raven {

    void Application::setup() {
        if (!glfwInit()) {
            throw Exception("Could not initialize GLFW!");
        }

        glfwWindowHint(GLFW_DOUBLEBUFFER, true);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        windowManager->create();
    }

    void Application::run() {
        while (!glfwWindowShouldClose(windowManager->getWindow())) {
            glfwPollEvents();

            // Delta Time
            double now = glfwGetTime();
            deltaTime = (now - lastTime);
            lastTime = now;
            updateTime += deltaTime / ( 1.0 / updateFps);

            // Update
            while (updateTime >= 1.0) {
                for (Object* object : sceneManager->getCurrentScene().getObjects()) {
                    object->update();
                }
                updateTime --;
            }

            // Render
            shaderManager->use("default");
            renderer->render();
            sceneManager->getCurrentScene().draw();
            glfwSwapBuffers(windowManager->getWindow());
        }
    }

    ShaderManager *Application::getShaderManager() const {
        return shaderManager;
    }

    void Application::setShaderManager(ShaderManager *shaderManager) {
        shaderManager->setApplication(this);
        this->shaderManager = shaderManager;
    }

    WindowManager *Application::getWindowManager() const {
        return windowManager;
    }

    void Application::setWindowManager(WindowManager *windowManager) {
        windowManager->setApplication(this);
        Application::windowManager = windowManager;
    }

    SceneManager *Application::getSceneManager() const {
        return sceneManager;
    }

    void Application::setSceneManager(SceneManager *sceneManager) {
        sceneManager->setApplication(this);
        Application::sceneManager = sceneManager;
    }

    Renderer *Application::getRenderer() const {
        return renderer;
    }

    void Application::setRenderer(OpenGLRenderer *renderer) {
        renderer->setApplication(this);
        Application::renderer = renderer;
    }

}

