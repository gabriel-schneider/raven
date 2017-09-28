//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "GLFW/glfw3.h"
#include "Application.h"
#include "Renderer.h"
#include "OpenGLRenderer.h"
#include "Exception.h"

namespace Raven {

    void Application::setup() {
        if (!glfwInit()) {
            throw Exception("Could not initialize GLFW!");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        WindowManager *windowMgr = (WindowManager*) serviceLocator->get("window");
        windowMgr->create();
    }

    void Application::run() {
        WindowManager *windowMgr = (WindowManager*) serviceLocator->get("window");

        while (!glfwWindowShouldClose(windowMgr->getWindow())) {
            glfwPollEvents();
            glfwSwapBuffers(windowMgr->getWindow());
        }
    }

    Application::Application(ServiceLocator &serviceLocator) {
        this->setServiceLocator(serviceLocator);
    }


}

