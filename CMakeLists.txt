cmake_minimum_required(VERSION 3.10)

project("Game")

include_directories("include")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
	src/main.cpp
	)

add_executable(game ${SOURCE_FILES})

