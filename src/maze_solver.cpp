#include "maze_solver.h"
#include <stack>
using namespace std;
// This function uses Depth-First Search (DFS) to find a path through the maze.
bool MazeSolver::dfs(Maze& maze, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= maze.grid.size() ||
        c < 0 || c >= maze.grid[0].size() ||
        maze.grid[r][c] == '#' ||
        visited[r][c]) {
        return false;
    }
  // If we reached the finish point, add it to the path and return true
    if (maze.grid[r][c] == 'F') {
        maze.path.push_back({r, c});
        return true;
    }

    visited[r][c] = true;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
 // Try going in each of the 4 directions
    for (int i = 0; i < 4; ++i) {
        int newR = r + dr[i];
        int newC = c + dc[i];
 // Recursively try to find the finish from the new spot
        if (dfs(maze, newR, newC, visited)) {
            maze.path.push_back({r, c});
            return true;
        }
    }

    return false;
}


bool MazeSolver::solveDFS(Maze& maze) {
    // Clear any existing path
    maze.path.clear();

    // Create visited matrix
    vector<vector<bool>> visited(maze.grid.size(),
                               vector<bool>(maze.grid[0].size(), false));

    // Start DFS from the start position
    bool found = dfs(maze, maze.start.row, maze.start.col, visited);

    // If path found, add the start position to the path
    if (found) {
        maze.path.push_back(maze.start);
    }

    return found;
}
