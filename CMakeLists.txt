cmake_minimum_required(VERSION 3.22)
project(s21_calculator VERSION 1.0
                       LANGUAGES C CXX)


# Configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})


# Build
add_subdirectory(src/)