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

        glfwWindowHint(GLFW_DOUBLEBUFFER, true);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        WindowManager *windowMgr = (WindowManager*) serviceLocator->get("window");
        windowMgr->create();
    }

    void Application::run() {
        WindowManager *windowMgr = (WindowManager*) getServiceLocator().get("window");
        Renderer *renderer = (Renderer*) getServiceLocator().get("renderer");

        while (!glfwWindowShouldClose(windowMgr->getWindow())) {
            glfwPollEvents();
            renderer->render();
            glfwSwapBuffers(windowMgr->getWindow());
        }
    }

    Application::Application(ServiceLocator &serviceLocator) {
        this->setServiceLocator(serviceLocator);
    }


}

