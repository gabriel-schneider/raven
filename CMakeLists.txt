cmake_minimum_required(VERSION 3.8)
project(raven)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/raven/Application.cpp src/raven/Application.h src/raven/Service.cpp src/raven/Service.h src/raven/ServiceLocator.cpp src/raven/ServiceLocator.h src/raven/DummyService.cpp src/raven/DummyService.h src/raven/Exception.cpp src/raven/Exception.h)
add_executable(raven ${SOURCE_FILES})