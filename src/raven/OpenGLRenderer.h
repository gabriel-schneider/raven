//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_OPENGLRENDER_H
#define RAVEN_OPENGLRENDER_H

#include "Renderer.h"
#include "GLFW/glfw3.h"

namespace Raven {
    class OpenGLRenderer : public Renderer {
//    protected:
//        GLFWwindow* window;
    public:
//        GLFWwindow *getWindow() const;
//        void setWindow(GLFWwindow *window);
        void setup() override;
        void render() override;
    };
}



#endif //RAVEN_OPENGLRENDER_H
