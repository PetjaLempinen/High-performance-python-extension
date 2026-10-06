#pragma once

#include <vector>
#include <cmath>

// Struct to hold (x, y) coordinates
struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Node structure for A* tracking
struct Node {
    Point pos;
    int g;
    int h;
    int f;
    Point parent;

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Function declaration for the pathfinder
std::vector<Point> findPath(const std::vector<std::vector<int>>& grid, Point start, Point end);