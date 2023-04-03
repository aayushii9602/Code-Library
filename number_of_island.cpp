#include <bits/stdc++.h>

using namespace std;

void bfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();
    // visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (q.size())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        // chekcing all the neighbours
        for (int rRange = -1; rRange <= 1; rRange++)
        {
            for (int cRange = -1; cRange <= 1; cRange++)
            {
                int newRow = row + rRange;
                int newCol = col + cRange;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
                {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int rRange = -1; rRange <= 1; rRange++)
    {
        for (int cRange = -1; cRange <= 1; cRange++)
        {
            int newRow = row + rRange;
            int newCol = col + cRange;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
            {
                visited[newRow][newCol] = 1;
                dfs(newRow, newCol, visited, grid);
            }
        }
    }
}

int numberOfIsland(vector<vector<int>> grid)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == 1 && visited[row][col] == 0)
            {
                count++;
                visited[row][col] = 1;
                // using DFS traversal
                dfs(row, col, visited, grid);

                // using BFS traversal
                // bfs(row, col, grid, visited);
            }
        }
    }
    return count;
}

int main()
{
    // count the number of islands
    // 1:land ; 0:water
    // An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
    vector<vector<int>> grid;
    grid = {{0, 1},
            {1, 0},
            {1, 1},
            {1, 0}};
    // using BFS traversal
    cout << "number OF island:" << numberOfIsland(grid) << endl;

    return 0;
}
