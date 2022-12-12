cmake_minimum_required(VERSION 3.10)
project(ScriptGenerator)

add_library(${PROJECT_NAME} src/generator.cpp src/generator.h)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)