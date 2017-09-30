//
// Created by Gabriel Schneider on 9/28/2017.
//

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "ShaderManager.h"
#include "Shader.h"

void Raven::Object::setup() {

    data = (Vertex*) malloc(sizeof(Vertex)*4);
    data[0].position = glm::vec3(0.0f, 0.0f, 0.0f);
    data[0].color = glm::vec3(1.0f, 0.0f, 0.0f);

    data[1].position = glm::vec3(32.0f, 0.0f, 0.0f);
    data[1].color = glm::vec3(1.0f, 0.0f, 0.0f);

    data[2].position = glm::vec3(0.0f, 32.0f, 0.0f);
    data[2].color = glm::vec3(0.0f, 1.0f, 0.0f);

    data[3].position = glm::vec3(32.0f, 32.0f, 0.0f);
    data[3].color = glm::vec3(1.0f, 1.0f, 1.0f);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*data)*4, data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);


}

void Raven::Object::render() {
    modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, 0.0f));
    ShaderManager* shaderManager = (ShaderManager*) serviceLocator->get("shaderManager");
    shaderManager->getActiveShader()->setMat4("model", modelMatrix);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
}
