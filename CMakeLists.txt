# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)

find_package(OpenGL REQUIRED)

# Compile external dependencies
add_subdirectory (External)


include_directories(
        External/glfw-3.1.2/include/
        External/glew-1.13.0/include/
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

# User playground
add_executable(Raycast main.cpp
        Player.cpp
        Player.h)

target_link_libraries(Raycast
        ${ALL_LIBS}
        )
