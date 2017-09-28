//
// Created by Gabriel Schneider on 9/27/2017.
//

#include "ServiceLocator.h"
#include "ServiceAware.h"
#include "Service.h"

void Raven::ServiceLocator::set(std::string name, Raven::ServiceAware *service) {
    service->setServiceLocator(*this);
    services[name] = service;
}

Raven::ServiceAware* Raven::ServiceLocator::get(std::string name) {
    return services.at(name);
}
