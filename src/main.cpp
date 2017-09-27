#include <iostream>
#include "raven/Application.h"
#include "raven/ServiceLocator.h"
#include "raven/DummyService.h"

int main() {

    Raven::ServiceLocator locator = Raven::ServiceLocator();

    Raven::Application app = Raven::Application(locator);

    Raven::DummyService dummyA = Raven::DummyService();
    printf("DummyA  address is %p\n", &dummyA);

    app.getServiceLocator().set("dummy", &dummyA);

    Raven::DummyService* dummyB = (Raven::DummyService*) (app.getServiceLocator().get("dummy"));
    printf("DummyB  address is %p\n", dummyB);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}