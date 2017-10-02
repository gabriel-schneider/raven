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
    dummy.x = 64;
    dummy.y = 64;
    dummy.width = 32;
    dummy.height = 32;

    while (!glfwWindowShouldClose(windowManager->getWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


//        double x, y;
//        glfwGetCursorPos(windowManager->getWindow(), &x, &y);
//        dummy.x = (float) x;
//        dummy.y = (float) y;

        shaderManager->use("default");
        glm::mat4 view;
        shaderManager->getActiveShader()->setUniform("view", view);
        renderer->render();
        dummy.texture.bind();
        dummy.draw();

        glfwPollEvents();
        glfwSwapBuffers(windowManager->getWindow());
    }

    app.run();

    return 0;
}