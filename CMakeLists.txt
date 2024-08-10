cmake_minimum_required(VERSION 3.28)
project(EngiNL)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG origin/main
        GIT_SHALLOW 1
        GIT_PROGRESS 1
        USES_TERMINAL_DOWNLOAD TRUE
)

FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
        SDL3_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG origin/main
        GIT_SHALLOW 1
        GIT_PROGRESS 1
        USES_TERMINAL_DOWNLOAD TRUE
)

FetchContent_MakeAvailable(SDL3_image)

set(CoreName EngiNLCore)

add_library(${CoreName}
            src/engine.hpp
            src/engine.cpp)

target_link_libraries(
        ${CoreName}
        PRIVATE SDL3::SDL3
        PRIVATE SDL3_image::SDL3_image)

target_include_directories(${CoreName} PRIVATE vendor/include)

add_executable(EngiNL main.cpp)

target_link_libraries(EngiNL ${CoreName})