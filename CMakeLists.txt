cmake_minimum_required(VERSION 3.8)
project(raven)

set(CMAKE_CXX_STANDARD 17)

# Include
include_directories(include)

# Source files
FILE(GLOB SOURCE_FILES "lib/*.c" "src/raven/*.h" "src/raven/*.cpp" "src/*.cpp")

# Resources
file(COPY res DESTINATION .)

# Linking
add_executable(raven ${SOURCE_FILES} src/raven/ApplicationAware.cpp src/raven/ApplicationAware.h)

if (UNIX)
    target_link_libraries(raven glfw GL dl)
endif()


if (WIN32)
    target_link_libraries(raven glfw3 opengl32)
endif()

