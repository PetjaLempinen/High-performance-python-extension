cmake_minimum_required(VERSION 3.15)
project(PathfinderEngine VERSION 1.0 LANGUAGES CXX)

# Require C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#library for our C++ core logic
add_library(cxx_core STATIC
    cxx_core/pathfinder.cpp
    cxx_core/pathfinder.hpp
)

# Allow other files to find headers inside the root folder
target_include_directories(cxx_core PUBLIC .)

# standalone test executable uses main.cpp
add_executable(pathfinder_test main.cpp)
target_link_libraries(pathfinder_test PRIVATE cxx_core)