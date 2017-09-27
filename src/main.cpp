#include <iostream>
#include "raven/Application.h"
#include "raven/DummyService.h"

int main() {

    auto locator = Raven::ServiceLocator();
    auto app = Raven::Application(locator);

    Raven::DummyService dummyA = Raven::DummyService();
    printf("DummyA  address is %p\n", &dummyA);

    app.getServiceLocator().set("dummy", &dummyA);

    Raven::DummyService* dummyB = (Raven::DummyService*) (app.getServiceLocator().get("dummy"));
    printf("DummyB  address is %p\n", dummyB);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}