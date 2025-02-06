cmake_minimum_required(VERSION 3.15)
project(ebvm)

set(EBVM_BUILD_TESTS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND EBVM_SOURCE
    src/ebvm.cpp
    src/processor.cpp
    src/stack.cpp
)

add_library(ebvm STATIC ${EBVM_SOURCE})
target_include_directories(ebvm PUBLIC include)

if(EBVM_BUILD_TESTS)
    add_subdirectory(tests)
endif()