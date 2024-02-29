cmake_minimum_required(VERSION 3.22)
project(propulsion_system)

set(CMAKE_CXX_STANDARD 20)

set(PYTHON_VERSION "3.10")

list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/python${PYTHON_VERSION}/dist-packages")

find_package(pybind11 CONFIG REQUIRED)

include_directories(${pybind11_INCLUDE_DIRS})

add_compile_options(
        -g
        -Wsign-compare
        -Wunreachable-code
        -DNDEBUG
        -O3
        -Wall
)

add_executable(propulsion_system main.cpp
        include/operationalPoint.h
        include/propulsion_system.h)

target_link_libraries(propulsion_system PUBLIC
        pybind11::embed
        nlopt
        dl
)
