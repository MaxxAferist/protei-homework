cmake_minimum_required(VERSION 3.14)
project(main)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall" )
set ( CMAKE_BUILD_TYPE DEBUG )


option(ENABLE_ASAN "Enable Address Sanitizer" OFF)
if(ENABLE_ASAN)
    message(STATUS "Address Sanitizer ENABLED")
    set(ASAN_FLAGS 
        -fsanitize=address
        -g
        -O1
        -fno-omit-frame-pointer
        -fno-optimize-sibling-calls
    )
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -fsanitize=undefined -g -O1 -fno-omit-frame-pointer -fno-optimize-sibling-calls")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
    
endif()


set( SRC_LIST   sources/main.cpp sources/vector_functions.cpp
                sources/mytools.cpp sources/mylogger.cpp
                sources/AppSettings.cpp sources/DataPool.cpp
                sources/Menu.cpp sources/Program.cpp )

add_executable( ${PROJECT_NAME} ${SRC_LIST} )

target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes )

# include(cmake/cppcheck.cmake)