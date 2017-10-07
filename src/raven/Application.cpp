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

        WindowManager *windowMgr = (WindowManager*) serviceLocator->get("window");
        windowMgr->create();
    }

    void Application::run() {

        auto *windowMgr = (WindowManager*) getServiceLocator().get("window");
        auto *renderer = (Renderer*) getServiceLocator().get("renderer");
        auto *sceneManager = (SceneManager*) getServiceLocator().get("sceneManager");
        auto *shaderManager = (ShaderManager*) getServiceLocator().get("shaderManager");

        //TODO: Pass this code to a camera object
//        glm::mat4 view;
//        shaderManager->getActiveShader()->setUniform("view", view);

        while (!glfwWindowShouldClose(windowMgr->getWindow())) {
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
            renderer->render();
            sceneManager->getCurrentScene().draw();
            glfwSwapBuffers(windowMgr->getWindow());
        }
    }

    Application::Application(ServiceLocator &serviceLocator) {
        this->setServiceLocator(serviceLocator);
    }

}

