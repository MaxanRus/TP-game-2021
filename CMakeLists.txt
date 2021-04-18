cmake_minimum_required(VERSION 3.10)

project("Game")

set(CMAKE_CXX_FLAGS "-O3")

add_custom_target(copy_assets ALL
        DEPENDS ${CMAKE_SOURCE_DIR}/assets
        VERBATIM)

add_custom_command(TARGET copy_assets
        PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
        COMMENT "Copy assets"
        VERBATIM)

include_directories("include")
include_directories("stb")

add_subdirectory(glfw)
add_subdirectory(glm)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
        stb/stb_image.cpp
        src/main.cpp
        src/graphics/Window.cpp
        src/graphics/Shader.cpp
        src/graphics/GShape.cpp
        src/engine/Drawable.cpp
        src/engine/Field.cpp
        src/engine/objects/Player.cpp
        src/engine/objects/Cell.cpp
        src/engine/objects/ground/GroundEarth.cpp
        src/engine/objects/ground/GroundWater.cpp
        src/engine/objects/Ground.cpp
        src/engine/objects/ground/GroundEmpty.cpp
        src/Console.cpp
        src/graphics/Transform.cpp
        src/Engine.cpp
        src/engine/WorldActor.cpp
        src/engine/objects/UnitGroup.cpp
        src/engine/objects/Unit.cpp
        src/Timer.cpp
        src/engine/objects/Building.cpp
        src/engine/Tickable.cpp
        src/engine/WorldActor.cpp
        src/ConstantsManager.cpp
        src/SpritesManager.cpp
        src/engine/objects/ground/Mineral.cpp
        src/graphics/ResourceManager.cpp
        src/Helpers/Vector2D.cpp
        src/EventHandler/EventHandler.cpp)

add_executable(game ${SOURCE_FILES})

target_link_libraries(game glfw)
target_link_libraries(game glm)
