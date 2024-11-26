cmake_minimum_required(VERSION 3.20)
project(sdl-first-app C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

if(APPLE)
    # On macOS, we need to link against the OpenGL framework
    find_library(OPENGL_FRAMEWORK OpenGL)
    if(NOT OPENGL_FRAMEWORK)
        message(FATAL_ERROR "OpenGL framework not found")
    endif()
endif()

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE
    SDL2::SDL2
    GLEW::GLEW
)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        "-framework OpenGL"
        "-framework Cocoa"
    )
endif()
