//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "WindowManager.h"
#include <string>
#include "Exception.h"

GLFWwindow *Raven::WindowManager::getWindow() const {
    return window;
}

void Raven::WindowManager::create(int width, int height, std::string caption) {
    this->width = width;
    this->height = height;
    this->caption = caption;
    GLFWwindow* w = glfwCreateWindow(width, height, caption.c_str(), NULL, NULL);
    if (!w) {
        glfwTerminate();
        throw Raven::Exception("Could not create window!");
    }
    glfwMakeContextCurrent(w);
    this->window = w;
}

const std::string &Raven::WindowManager::getCaption() const {
    return caption;
}

void Raven::WindowManager::setCaption(const std::string &caption) {
    WindowManager::caption = caption;
}

int Raven::WindowManager::getWidth() const {
    return width;
}

void Raven::WindowManager::setWidth(int width) {
    WindowManager::width = width;
}

int Raven::WindowManager::getHeight() const {
    return height;
}

void Raven::WindowManager::setHeight(int height) {
    WindowManager::height = height;
}

void Raven::WindowManager::create() {
    create(this->width, this->height, this->caption);
}
