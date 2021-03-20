cmake_minimum_required(VERSION 3.10)

project("Game")

# set(CMAKE_CXX_FLAGS "-O3")

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
		include/graphics/Window.hpp
		src/graphics/Window.cpp
		include/graphics/Shader.hpp
		src/graphics/Shader.cpp
		include/graphics/GShape.hpp
		src/graphics/GShape.cpp
		src/engine/Drawable.cpp
        include/engine/Drawable.hpp
		src/engine/Field.cpp
		include/engine/Field.hpp
		src/engine/objects/Player.cpp
		include/engine/objects/Player.hpp
		src/engine/objects/Cell.cpp
		include/engine/objects/Cell.hpp
		src/engine/objects/ground/GroundEarth.cpp
		include/engine/objects/ground/GroundEarth.hpp
		src/engine/objects/ground/GroundWater.cpp
		include/engine/objects/ground/GroundWater.hpp
		src/engine/objects/Ground.cpp
		include/engine/objects/Ground.hpp
		include/Console.hpp
		src/engine/objects/ground/GroundEmpty.cpp
		include/engine/objects/ground/GroundEmpty.hpp
		src/Console.cpp
		src/engine/objects/ground/earth/Dirt.cpp
		include/engine/objects/ground/earth/Dirt.hpp
		src/engine/objects/ground/earth/Stone.cpp
		include/engine/objects/ground/earth/Stone.hpp
		include/graphics/Transform.hpp
		src/graphics/Transform.cpp
		src/Engine.cpp
		include/Engine.hpp
		src/engine/objects/ground/water/Water.cpp
		include/engine/objects/ground/water/Water.hpp
		src/engine/Tickable.cpp
		include/engine/Tickable.hpp
		src/engine/Movable.cpp
		include/engine/Movable.hpp
		src/GlobalVariablesManager.cpp
		include/GlobalVariablesManager.hpp
		src/GlobalClassManager.cpp
		include/GlobalClassManager.hpp
		src/engine/objects/UnitGroup.cpp
		include/engine/objects/UnitGroup.hpp
		src/engine/objects/Unit.cpp
		include/engine/objects/Unit.hpp
		src/Timer.cpp
		include/Timer.hpp
		src/engine/objects/Building.cpp
		include/engine/objects/Building.hpp
		include/graphics/ResourceManager.hpp
		include/engine/objects/ground/water/Water.hpp
		src/engine/Tickable.cpp
		include/engine/Tickable.hpp
		src/engine/Movable.cpp
		include/engine/Movable.hpp
		src/GlobalVariablesManager.cpp
		include/GlobalVariablesManager.hpp
		src/GlobalClassManager.cpp
		include/GlobalClassManager.hpp
		src/engine/objects/ground/Mineral.cpp
		include/engine/objects/ground/Mineral.hpp
		src/engine/objects/ground/mineral/Iron.cpp
		include/engine/objects/ground/mineral/Iron.hpp
		src/engine/objects/ground/mineral/Copper.cpp
		include/engine/objects/ground/mineral/Copper.hpp)

add_executable(game ${SOURCE_FILES})

target_link_libraries(game glfw)
target_link_libraries(game glm)
