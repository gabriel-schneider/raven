#include <iostream>
#include "raven/Application.h"
#include "raven/DummyService.h"
#include "raven/OpenGLRenderer.h"

int main() {

    auto locator = Raven::ServiceLocator();
    locator.set("render", new Raven::OpenGLRenderer());

    auto windowManager = new Raven::WindowManager();
    windowManager->setWidth(640);
    windowManager->setHeight(480);
    windowManager->setCaption("Raven Application");
    locator.set("window", windowManager);

    auto app = Raven::Application(locator);
    app.setup();
    app.run();

    return 0;
}