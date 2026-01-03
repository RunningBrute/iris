cmake_minimum_required(VERSION 3.21)

project(iris
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(iris
    src/main.cpp
)

target_include_directories(iris
    PRIVATE
        inc
)

if (MSVC)
    target_compile_options(iris PRIVATE /W4 /permissive-)
else()
    target_compile_options(iris PRIVATE -Wall -Wextra -Wpedantic)
endif()
