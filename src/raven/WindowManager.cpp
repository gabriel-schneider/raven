//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "WindowManager.h"
#include <string>
#include "Exception.h"

namespace Raven {

    GLFWwindow *Raven::WindowManager::getWindow() const {
        return window;
    }

    void WindowManager::create(int width, int height, std::string caption) {
        this->width = width;
        this->height = height;
        this->caption = caption;
        GLFWwindow* w = glfwCreateWindow(width, height, caption.c_str(), NULL, NULL);
        if (!w) {
            glfwTerminate();
            throw Exception("Could not create window!");
        }
        glfwMakeContextCurrent(w);
        this->window = w;
    }

    const std::string &WindowManager::getCaption() const {
        return caption;
    }

    void WindowManager::setCaption(const std::string &caption) {
        WindowManager::caption = caption;
    }

    int WindowManager::getWidth() const {
        return width;
    }

    void WindowManager::setWidth(int width) {
        WindowManager::width = width;
    }

    int WindowManager::getHeight() const {
        return height;
    }

    void WindowManager::setHeight(int height) {
        WindowManager::height = height;
    }

    void WindowManager::create() {
        create(this->width, this->height, this->caption);
    }

}