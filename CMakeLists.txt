cmake_minimum_required(VERSION 3.8)
project(raven)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
set(SOURCE_FILES
        src/glad.c
        src/raven/ServiceLocator.cpp src/raven/ServiceLocator.h
        src/raven/Service.cpp src/raven/Service.h
        src/raven/ServiceAware.cpp src/raven/ServiceAware.h
        src/raven/DummyService.cpp src/raven/DummyService.h
        src/raven/Exception.cpp src/raven/Exception.h
        src/main.cpp src/raven/Application.cpp src/raven/Application.h src/raven/Renderer.cpp src/raven/Renderer.h src/raven/OpenGLRenderer.cpp src/raven/OpenGLRenderer.h src/raven/WindowManager.cpp src/raven/WindowManager.h)

add_executable(raven ${SOURCE_FILES})
target_link_libraries(raven glfw3 opengl32)

