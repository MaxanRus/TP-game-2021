cmake_minimum_required(VERSION 3.10)

project("Game")

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
    )

add_executable(game ${SOURCE_FILES})

target_link_libraries(game glfw)
target_link_libraries(game glm)

