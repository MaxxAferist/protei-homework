cmake_minimum_required(VERSION 3.14)
project(tests)


include(FetchContent)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized -Wno-maybe-uninitialized")
endif()

FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git 
    GIT_TAG v1.10.x
)
FetchContent_MakeAvailable(googletest)

set(FETCHCONTENT_QUIET ON)
set(gtest_quiet ON)

set( TEST_SOURCES main_test.cpp )

add_executable( ${PROJECT_NAME} ${TEST_SOURCES} )

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../includes
    ${gtest_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)

target_sources(${PROJECT_NAME} PRIVATE
    # ${CMAKE_CURRENT_SOURCE_DIR}/../sources/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../sources/mylogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../sources/mytools.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../sources/vector_functions.cpp
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
