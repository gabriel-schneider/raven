//
// Created by Gabriel Schneider on 9/28/2017.
//

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Object.h"
#include "ShaderManager.h"
#include "Shader.h"
#include "Application.h"

void Raven::Object::setup() {

    this->data = (Vertex*) malloc(sizeof(Vertex)*4);
    this->data[0].position = Vector3(-1.0f, -1.0f, 0.0f);
    this->data[0].color = Vector3(1.0f, 0.0f, 0.0f);
    this->data[0].uv = Vector2(0.0f, 0.0f);

    this->data[1].position = Vector3(1.0f, -1.0f, 0.0f);
    this->data[1].color = Vector3(1.0f, 0.0f, 0.0f);
    this->data[1].uv = Vector2(1.0f, 0.0f);

    this->data[2].position = Vector3(-1.0f, 1.0f, 0.0f);
    this->data[2].color = Vector3(0.0f, 1.0f, 0.0f);
    this->data[2].uv = Vector2(0.0f, 1.0f);

    this->data[3].position = Vector3(1.0f, 1.0f, 0.0f);
    this->data[3].color = Vector3(1.0f, 1.0f, 1.0f);
    this->data[3].uv = Vector2(1.0f, 1.0f);

    this->indices = (unsigned int*) malloc(sizeof(unsigned int)*4);
    this->indices[0] = 0;
    this->indices[1] = 1;
    this->indices[2] = 2;
    this->indices[3] = 3;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*data)*4, data, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(*indices)*4, indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);


}

void Raven::Object::draw() {
    updateModelMatrix();
    ShaderManager* shaderManager = getApplication()->getShaderManager();
    shaderManager->getActiveShader()->setUniform("model", modelMatrix);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
}

void Raven::Object::updateModelMatrix() {
    Matrix4 model = glm::translate(Matrix4(), Vector3(x, y, z));
    model = glm::rotate(model, glm::radians(rotx), Vector3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(roty), Vector3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotz), Vector3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, Vector3(scalex*width, scaley*height, scalez));
    modelMatrix = model;
}

