#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> game)
{
    int n = game.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (game[i] > game[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    // there are two player
    // each can remove either game[0] or game[n-1]th element
    // The player adds the chosen number to their score.
    // The game ends when there are no more elements in the array.
    // If the scores of both players are equal, then player 1 is still the winner.
    // determine which player wins
    vector<int> game = {1, 5, 2};
    // find longest increasing subsequence
    int length = lis(game);
    if (length % 2 == 0)
        cout << "Player2\n";
    else
        cout << "Player1\n";
    game = {1, 5, 233, 7};
    length = lis(game);
    if (length % 2 == 0)
        cout << "Player2\n";
    else
        cout << "Player1\n";

    return 0;
}
