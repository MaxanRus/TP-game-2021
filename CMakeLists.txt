cmake_minimum_required(VERSION 3.10)

project("Game")

add_custom_target(copy_shaders ALL
		DEPENDS ${CMAKE_SOURCE_DIR}/shaders
		VERBATIM)

add_custom_command(TARGET copy_shaders
		PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/shaders
		${CMAKE_BINARY_DIR}/shaders
		COMMENT "Copy shaders"
		VERBATIM)

include_directories("include")

add_subdirectory(glfw)
add_subdirectory(glm)

include_directories("stb")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glad/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)

set(CMAKE_CXX_STANDARD 17)

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
		)

add_executable(game ${SOURCE_FILES})

target_link_libraries(game glfw)
target_link_libraries(game glm)
