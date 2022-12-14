cmake_minimum_required(VERSION 3.10)
project(ScriptGenerator)

add_library(${PROJECT_NAME} src/HMScriptGenerator.cpp src/HMScriptGenerator.h)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
