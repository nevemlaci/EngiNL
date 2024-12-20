cmake_minimum_required(VERSION 3.28)
project(EngiNL)


set(CMAKE_CXX_STANDARD 26)

#set lua path here
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};C:/Program Files (x86)/Lua/5.4.7")

link_directories(vendor/lib)

function(copy_depend_dlls target_name)
    if(WIN32)
        add_custom_command(TARGET ${target_name} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:${target_name}> $<TARGET_RUNTIME_DLLS:${target_name}>
                COMMAND_EXPAND_LISTS
        )
    endif (WIN32)
endfunction()

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

find_package(Lua 5.4 REQUIRED)

FetchContent_Declare(
        sol2
        GIT_REPOSITORY https://github.com/ThePhD/sol2.git
        GIT_TAG origin/develop
        GIT_SHALLOW 1
        GIT_PROGRESS 1
        USES_TERMINAL_DOWNLOAD TRUE
)

FetchContent_MakeAvailable(sol2)

find_package(SDL3)

if (NOT SDL3_FOUND)
    FetchContent_Declare(
            SDL3
            GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
            GIT_TAG preview-3.1.6
            GIT_SHALLOW 1
            GIT_PROGRESS 1
            USES_TERMINAL_DOWNLOAD TRUE
    )

    FetchContent_MakeAvailable(SDL3)
endif ()

find_package(SDL3_image)

if(NOT SDL3_image_FOUND)
    FetchContent_Declare(
            SDL3_image
            GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
            GIT_TAG 0d418a2a2dc562699854d9c2fc264304ec404e2c
            GIT_SHALLOW 1
            GIT_PROGRESS 1
            USES_TERMINAL_DOWNLOAD TRUE
    )

    FetchContent_MakeAvailable(SDL3_image)
endif ()



FetchContent_Declare(
        ccmath
        GIT_REPOSITORY https://github.com/Rinzii/ccmath.git
        GIT_TAG v0.1.5
        GIT_SHALLOW 1
        GIT_PROGRESS 1
        USES_TERMINAL_DOWNLOAD TRUE
)

FetchContent_MakeAvailable(ccmath)

add_library(
        EngiNLCore SHARED
        src/engine.hpp
        src/engine.cpp
        src/scene.cpp
        src/scene.hpp
        src/entity.cpp
        src/entity.hpp
        src/EngiNL.hpp
        src/AssetManager.cpp
        src/AssetManager.hpp
        src/entt_include.hpp
        src/Component/sprite_renderer.hpp
        src/Component/transform.hpp
        src/Maths/Vector2.hpp
        src/System/sprite_renderer_system.hpp
        src/System/sprite_renderer_system.cpp
        src/export.hpp
        src/Component/sprite_renderer.cpp
        src/Component/sprite_renderer.cpp
        src/Component/custom_script_holder.hpp
        src/Component/custom_script_holder.hpp
        src/Component/custom_script_holder.cpp
        src/Interface/iscript.cpp
)


if(MSVC)
    target_compile_options(EngiNLCore
            PRIVATE /permissive
            PRIVATE /external:anglebrackets
            PRIVATE /external:W0)
endif (MSVC)

include(GenerateExportHeader)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

target_link_libraries(
        EngiNLCore
        PRIVATE SDL3::SDL3
        PRIVATE SDL3_image::SDL3_image
        PRIVATE ${LUA_LIBRARIES}
        PRIVATE sol2::sol2
        PRIVATE ccmath::ccmath
)

target_include_directories(EngiNLCore PRIVATE vendor/include PRIVATE ${LUA_INCLUDE_DIR})

add_executable(EngiNL main.cpp
        src/Interface/iscript.hpp
        src/Interface/iscript.cpp)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(
        EngiNL
        PRIVATE EngiNLCore
        PRIVATE SDL3::SDL3
        PRIVATE SDL3_image::SDL3_image
        PRIVATE ${LUA_LIBRARIES}
        PRIVATE sol2::sol2
        PRIVATE ccmath::ccmath
)

if(MSVC)
    target_compile_options(EngiNL
            PRIVATE /permissive
            PRIVATE /external:anglebrackets
            PRIVATE /external:W0)
endif (MSVC)



target_include_directories(EngiNL PRIVATE vendor/include PRIVATE ${LUA_INCLUDE_DIR})

copy_depend_dlls(EngiNLCore)
copy_depend_dlls(EngiNL)

target_include_directories(EngiNL PRIVATE src)

target_include_directories(EngiNLCore
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS EngiNLCore
        EXPORT EngiNLCoreTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

FILE(GLOB_RECURSE header_list "src/*.hpp")
install(FILES ${header_list} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/EngiNLCoreConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/../cmake/EngiNLCore
)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/EngiNLCoreConfigVersion.cmake"
        VERSION 0.0.1
        COMPATIBILITY AnyNewerVersion)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/EngiNLCoreConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/EngiNLCoreConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/../cmake/EngiNLCore
)

