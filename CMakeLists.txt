cmake_minimum_required(VERSION 3.22)
project(s21_calculator VERSION 1.0
                       LANGUAGES C CXX)


# Configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


# Build
add_subdirectory(src/)