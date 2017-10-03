#include <iostream>

#include "raven/raven.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Raven;

int main() {
    //TODO: Make a better workflow

    auto locator = ServiceLocator();

    OpenGLRenderer *renderer = new OpenGLRenderer();
    renderer->setProjectionMatrix(glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f));
    locator.set("renderer", renderer);

    auto windowManager = new WindowManager();
    windowManager->setWidth(640);
    windowManager->setHeight(480);
    windowManager->setCaption("Raven Application");

    locator.set("window", windowManager);

    auto app = Raven::Application(locator);
    app.setup();
    renderer->setup();

    glViewport(0, 0, 640, 480);

    ShaderManager *shaderManager = new ShaderManager("res/shaders");
    locator.set("shaderManager", shaderManager);
    shaderManager->createShader("default", "default.vert", "default.frag");
    shaderManager->use("default");

    Object dummy;
    dummy.setServiceLocator(locator);
    dummy.setup();
    dummy.texture.load("res/textures/wooden.jpg");
    dummy.texture.bind();
    dummy.x = 128;
    dummy.y = 128;
    dummy.width = 64;
    dummy.height = 64;
    double lastTime = 1, deltaTime = 1, fps = 1.0/60.0;

    while (!glfwWindowShouldClose(windowManager->getWindow())) {
        glfwPollEvents();

        deltaTime += (glfwGetTime() - lastTime) / fps;
        lastTime = glfwGetTime();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

//        double x, y;
//        glfwGetCursorPos(windowManager->getWindow(), &x, &y);
//        dummy.x = (float) x;
//        dummy.y = (float) y;

        while (deltaTime >= 1.0)
        {
            dummy.rotz += 1;
            deltaTime --;
        }


        shaderManager->use("default");
        glm::mat4 view;
        shaderManager->getActiveShader()->setUniform("view", view);
        renderer->render();
        dummy.texture.bind();
        dummy.draw();


        glfwSwapBuffers(windowManager->getWindow());
    }

    app.run();

    return 0;
}