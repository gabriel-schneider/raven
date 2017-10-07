//
// Created by Gabriel Schneider on 9/27/2017.
//

#ifndef RAVEN_WINDOW_H
#define RAVEN_WINDOW_H

#include <GLFW/glfw3.h>
#include <string>
#include "ApplicationAware.h"

namespace Raven {
    class WindowManager : public ApplicationAware {
    protected:
        GLFWwindow* window;
        std::string caption;
    public:
        const std::string &getCaption() const;

        void setCaption(const std::string &caption);

        int getWidth() const;

        void setWidth(int width);

        int getHeight() const;

        void setHeight(int height);

    protected:
        int width;
        int height;
    public:
        GLFWwindow *getWindow() const;
        void create(int width, int height, std::string caption);
        void create();

    };
}


#endif //RAVEN_WINDOW_H
