#include <bits/stdc++.h>

using namespace std;

bool bfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool ans = true;

    while (q.size())
    {
        row = q.front().first;
        col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    if (grid[nrow][ncol] == 0 && !visited[nrow][ncol])
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
                else
                {
                    ans = false;
                }
            }
        }
    }
    return ans;
}
int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 0 && bfs(i, j, grid, visited))
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    // An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << "number of closed islands: " << closedIsland(grid) << endl;
    return 0;
}