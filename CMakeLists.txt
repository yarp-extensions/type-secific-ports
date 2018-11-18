cmake_minimum_required(VERSION 3.12)
project(TypeSpecificPorts)

set(CMAKE_CXX_STANDARD 17)

add_library(TypeSpecificPorts SHARED TypeTemplate.cpp TypeTemplate.h)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing()
add_subdirectory(tests)