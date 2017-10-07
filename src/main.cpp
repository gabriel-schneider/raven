#include <iostream>

#include "raven/raven.h"
#include "raven/Scene.h"
#include "raven/SceneManager.h"
#include "DummyObject.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Raven;

int main() {
    //TODO: Make a better workflow

    auto locator = ServiceLocator();

    OpenGLRenderer *renderer = new OpenGLRenderer();
    renderer->setProjectionMatrix(glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f));
    renderer->camera = new Camera();
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

    DummyObject dummy;
    dummy.setServiceLocator(locator);
    dummy.setup();
    dummy.texture.load("res/textures/wooden.jpg");
    dummy.texture.bind();
    dummy.x = 128;
    dummy.y = 128;
    dummy.rotz = 10;
    dummy.width = 64;
    dummy.height = 64;

    auto *sceneManager = new SceneManager();
    locator.set("sceneManager", sceneManager);
    sceneManager->setCurrentScene(*(new Scene()));

    sceneManager->getCurrentScene().add(dummy);

    app.run();

    return 0;
}