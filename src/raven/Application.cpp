//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "GLFW/glfw3.h"
#include "Application.h"
#include "Renderer.h"
#include "OpenGLRenderer.h"
#include "Exception.h"
void Raven::Application::run() {
    Raven::WindowManager *windowMgr = (Raven::WindowManager*) serviceLocator->get("window");

    while (!glfwWindowShouldClose(windowMgr->getWindow())) {
        glfwPollEvents();
        glfwSwapBuffers(windowMgr->getWindow());
    }
}

Raven::Application::Application(Raven::ServiceLocator &serviceLocator) {
    this->setServiceLocator(serviceLocator);
}

void Raven::Application::setup() {
    if (!glfwInit()) {
        throw Raven::Exception("Could not initialize GLFW!");
    }
    Raven::WindowManager *windowMgr = (Raven::WindowManager*) serviceLocator->get("window");
    windowMgr->create();
}
