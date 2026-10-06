#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../cxx_core/pathfinder.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pathfinder_ext, m) {
    m.doc() = "High-performance A* pathfinder C++ extension";

    // Expose Point struct for python
    py::class_<Point>(m, "Point")
        .def(py::init<int, int>())
        .def_readwrite("x", &Point::x)
        .def_readwrite("y", &Point::y)
        .def("__repr__", [](const Point& p) {
            return "Point(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
        });

    // Expose the findPath function
    m.def("find_path", &findPath, "A function that finds a path using A*");
}