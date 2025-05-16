cmake_minimum_required(VERSION 3.10)
project(game)

cmake_policy(SET CMP0072 NEW)  # Must go before find_package

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE s src/*.cpp external/*/src/*.[cC]*)
file(GLOB external/*/include i LIST_DIRECTORIES true)

include_directories(${i} src)

find_package(OpenGL REQUIRED)  # No warning now

add_executable(game ${s})
target_link_libraries(game OpenGL::GL glfw)
