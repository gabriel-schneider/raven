#include <iostream>
#include "raven/Application.h"
#include "raven/DummyService.h"
#include "raven/OpenGLRenderer.h"
#include "raven/ShaderManager.h"

using namespace Raven;

int main() {
    //TODO: Make a better workflow

    auto locator = ServiceLocator();

    OpenGLRenderer *renderer = new OpenGLRenderer();
    locator.set("render", renderer);

    auto windowManager = new WindowManager();
    windowManager->setWidth(640);
    windowManager->setHeight(480);
    windowManager->setCaption("Raven Application");
    locator.set("window", windowManager);


    auto app = Raven::Application(locator);
    app.setup();
    renderer->setup();
    auto *shaderManager = new ShaderManager("res/shaders");
    shaderManager->createShader("default", "default.vert", "default.frag");
    app.run();

    return 0;
}