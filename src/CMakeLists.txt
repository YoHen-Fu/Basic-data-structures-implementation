cmake_minimum_required(VERSION 3.3)

project(test)

set(HOME D:/Document/4_Projects/gitee/basic-data-structures-implementation/src)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/data_structure/*.cpp)
list(APPEND SRC_LIST ${SRC_LIST} main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin/)
include_directories(${PROJECT_SOURCE_DIR}/data_structure)

add_executable(test ${SRC_LIST})