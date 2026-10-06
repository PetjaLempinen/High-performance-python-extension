#include <vector>
#include <iostream>
#include "cxx_core/pathfinder.hpp"

int main() {
    // 15x15 Grid representation (0 = Open, 1 = Wall/Obstacle)
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point end = {14, 14};

    // Call our C++ core function
    std::vector<Point> path = findPath(grid, start, end);

    if (!path.empty()) {
        std::cout << "Path found! Total steps: " << path.size() << "\n";
        int count = 0;
        for (const auto& p : path) {
            std::cout << "(" << p.x << ", " << p.y << ") ";
            count++;
            if (count % 8 == 0) {
                std::cout << "\n";
            }
        }
        std::cout << "\n";
    } else {
        std::cout << "No path found!\n";
    }

    return 0;
}