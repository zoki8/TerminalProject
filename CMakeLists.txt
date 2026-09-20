cmake_minimum_required(VERSION 3.10)
project(minishell-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(cmi main.cpp ${SOURCES})
target_include_directories(cmi PRIVATE include include/Commands)
