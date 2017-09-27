#include <iostream>
#include "raven/Application.h"
#include "raven/DummyService.h"
#include "raven/OpenGLRender.h"
int main() {

    auto locator = Raven::ServiceLocator();
    locator.set("render", new Raven::OpenGLRender());

    auto app = Raven::Application(locator);
    app.run();

    return 0;
}