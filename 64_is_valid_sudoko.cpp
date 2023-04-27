#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        map<char, int> m;
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (m[board[i][j]] == 0)
                    m[board[i][j]] = 1;
                else
                    return false;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        map<char, int> m;
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.')
            {
                if (m[board[j][i]] == 0)
                    m[board[j][i]] = 1;
                else
                    return false;
            }
        }
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            map<char, int> m;
            for (int v = i; v < i + 3; v++)
            {
                for (int k = j; k < j + 3; k++)
                {
                    if (board[v][k] != '.')
                    {
                        if (m[board[v][k]] == 0)
                            m[board[v][k]] = 1;
                        else
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    // Each row must contain the digits 1-9 without repetition.
    // Each column must contain the digits 1 - 9 without repetition.
    // Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
    // A Sudoku board (partially filled) could be valid but is not necessarily solvable.

    vector<vector<char>> v = {{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                              {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                              {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                              {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                              {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                              {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                              {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
    if (isValidSudoku(v))
        cout << "VALID\n";
    else
        cout << "NOT VALID\n";
    return 0;
}