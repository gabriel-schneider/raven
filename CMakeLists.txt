cmake_minimum_required(VERSION 3.8)
project(raven)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

FILE(GLOB SOURCE_FILES "lib/*.c" "src/raven/*.h" "src/raven/*.cpp" "src/*.cpp")

file(COPY res DESTINATION .)
add_executable(raven ${SOURCE_FILES})

if (UNIX)
    target_link_libraries(raven glfw GL dl)
endif(UNIX)

if (WINDOWS)
    target_link_libraries(raven glfw3 opengl32 gdi)
endif(WINDOWS)

