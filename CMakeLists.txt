cmake_minimum_required(VERSION 3.8)
project(myproject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")

set(SRC_LIST sources/main.cpp sources/vector_functions.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(myproject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
