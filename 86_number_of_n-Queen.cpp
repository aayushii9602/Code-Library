#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int r = row, c = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = r, col = c;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    col = c, row = r;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, int &count, int n)
{
    if (col == n)
    {
        count++;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, count, n);
            board[row][col] = '.';
        }
    }
}

int NQueen(int n)
{
    int count = 0;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
        board[i] = s;

    solve(0, board, count, n);
    return count;
}
int main()
{
    int n = 4;
    cout << "The number of distinct solutions to the n-queens puzzle: " << NQueen(n) << endl;
    return 0;
}