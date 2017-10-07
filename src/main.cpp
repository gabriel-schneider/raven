#include <iostream>

#include "raven/raven.h"
#include "raven/Scene.h"
#include "raven/SceneManager.h"
#include "DummyObject.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Raven;

int main() {

    Application app;

    OpenGLRenderer renderer;
    renderer.setProjectionMatrix(glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f));
    renderer.camera = new Camera();
    app.setRenderer(&renderer);

    WindowManager windowManager;
    windowManager.setWidth(640);
    windowManager.setHeight(480);
    windowManager.setCaption("Raven Application");
    app.setWindowManager(&windowManager);

    app.setup();
    renderer.setup();

    glViewport(0, 0, 640, 480);

    ShaderManager shaderManager("res/shaders");
    shaderManager.createShader("default", "default.vert", "default.frag");
    shaderManager.use("default");
    app.setShaderManager(&shaderManager);

    SceneManager sceneManager;
    sceneManager.setCurrentScene(*(new Scene()));
    app.setSceneManager(&sceneManager);

    DummyObject dummy;
    dummy.setup();
    dummy.texture.load("res/textures/wooden.jpg");
    dummy.texture.bind();
    dummy.x = 128;
    dummy.y = 128;
    dummy.rotz = 10;
    dummy.width = 64;
    dummy.height = 64;

    sceneManager.getCurrentScene().add(dummy);

    app.run();

    return 0;
}