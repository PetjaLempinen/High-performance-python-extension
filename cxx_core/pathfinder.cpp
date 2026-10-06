#include "pathfinder.hpp"
#include <queue>
#include <algorithm>

// Heuristic function: Manhattan distance
int calculateHeuristic(Point a, Point b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// Full A* Pathfinding Logic
std::vector<Point> findPath(const std::vector<std::vector<int>>& grid, Point start, Point end) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;

    std::vector<std::vector<bool>> closedSet(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<int>> gCosts(rows, std::vector<int>(cols, 1e9));
    std::vector<std::vector<Point>> cameFrom(rows, std::vector<Point>(cols, {-1, -1}));

    int startH = calculateHeuristic(start, end);
    openSet.push({start, 0, startH, startH, {-1, -1}});
    gCosts[start.y][start.x] = 0;

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.pos == end) {
            std::vector<Point> path;
            Point curr = end;
            while (!(curr.x == -1 && curr.y == -1)) {
                path.push_back(curr);
                curr = cameFrom[curr.y][curr.x];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        if (closedSet[current.pos.y][current.pos.x]) continue;
        closedSet[current.pos.y][current.pos.x] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = current.pos.x + dx[i];
            int ny = current.pos.y + dy[i];

            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && grid[ny][nx] == 0) {
                if (closedSet[ny][nx]) continue;

                int tentativeG = gCosts[current.pos.y][current.pos.x] + 1;

                if (tentativeG < gCosts[ny][nx]) {
                    gCosts[ny][nx] = tentativeG;
                    int h = calculateHeuristic({nx, ny}, end);
                    int f = tentativeG + h;
                    
                    cameFrom[ny][nx] = current.pos;
                    openSet.push({{nx, ny}, tentativeG, h, f, current.pos});
                }
            }
        }
    }

    return {}; // Return empty if no path
}