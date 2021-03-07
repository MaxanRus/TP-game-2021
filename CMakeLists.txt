cmake_minimum_required(VERSION 3.10)

project("Game")

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
		src/Object.cpp
		include/Object.hpp
		src/Field.cpp
		include/Field.hpp
		src/objects/Player.cpp
		include/objects/Player.hpp
		src/objects/Cell.cpp
		include/objects/Cell.hpp
		src/objects/ground/GroundEarth.cpp
		include/objects/ground/GroundEarth.hpp
		src/objects/ground/GroundWater.cpp
		include/objects/ground/GroundWater.hpp
		src/objects/Ground.cpp
		include/objects/Ground.hpp
		include/Console.hpp
		src/objects/ground/GroundEmpty.cpp
		include/objects/ground/GroundEmpty.hpp
		src/Console.cpp
		src/objects/ground/earth/Earth.cpp
		include/objects/ground/earth/Earth.hpp
		src/objects/ground/earth/Stone.cpp include/objects/ground/earth/Stone.hpp)

add_executable(game ${SOURCE_FILES})

target_link_libraries(game glfw)
target_link_libraries(game glm)
