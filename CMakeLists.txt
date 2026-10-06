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

# Automatically find pybind11 via Python executable
execute_process(
  COMMAND python -c "import pybind11; print(pybind11.get_cmake_dir())"
  OUTPUT_VARIABLE pybind11_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
# Use modern FindPython and target our virtual environment
set(PYBIND11_FINDPYTHON ON)
find_package(Python 3.9 REQUIRED COMPONENTS Interpreter Development)

# Find pybind11 via Python
find_package(pybind11 REQUIRED)

# Create the Python extension module
pybind11_add_module(pathfinder_ext bindings/pathfinder_py.cpp)
target_link_libraries(pathfinder_ext PRIVATE cxx_core)