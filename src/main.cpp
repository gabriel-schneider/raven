#include <iostream>

#include "raven/raven.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Raven;

int main() {
    //TODO: Make a better workflow

    auto locator = ServiceLocator();

    OpenGLRenderer *renderer = new OpenGLRenderer();
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
    shaderManager->get("default").use();

//    auto data = (Vertex*) malloc(sizeof(Vertex)*4);
//    data[0].position = glm::vec3(-32.0f, -32.0f, 0.0f);
//    data[0].color = glm::vec3(1.0f, 0.0f, 0.0f);
//
//    data[1].position = glm::vec3(32.0f, -32.0f, 0.0f);
//    data[1].color = glm::vec3(1.0f, 0.0f, 0.0f);
//
//    data[2].position = glm::vec3(-32.0f, 32.0f, 0.0f);
//    data[2].color = glm::vec3(0.0f, 1.0f, 0.0f);
//
//    data[3].position = glm::vec3(32.0f, 32.0f, 0.0f);
//    data[3].color = glm::vec3(1.0f, 1.0f, 1.0f);

    Vertex data[] = {
            glm::vec3(-32.0f, -32.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),

            glm::vec3(32.0f, -32.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),

            glm::vec3(-32.0f, 32.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),

            glm::vec3(32.0f, 32.0f, 0.0f),
            glm::vec3(1.0f, 1.0f, 1.0f)
    };

    GLuint indexes[] = {0, 1, 2, 3};

    unsigned int vao;
    glGenVertexArrays(1, &vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);

    unsigned int ebo;
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

    glBindVertexArray(0);


    while (!glfwWindowShouldClose(windowManager->getWindow())) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 view, model;
        double x, y;
        glfwGetCursorPos(windowManager->getWindow(), &x, &y);
        model = glm::translate(model, glm::vec3(x, y, 0.0f));
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        shaderManager->use("default");
        shaderManager->getActiveShader()->setMat4("view", view);
        shaderManager->getActiveShader()->setMat4("projection", glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f));
        shaderManager->getActiveShader()->setMat4("model", model);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);

        glfwPollEvents();
        glfwSwapBuffers(windowManager->getWindow());
    }

    app.run();

    return 0;
}