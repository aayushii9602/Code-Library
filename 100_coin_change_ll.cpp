#include <bits/stdc++.h>

using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // int dp[n] = new int[amount + 1];
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // base case
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= amount; j++)
            if (j - coins[i] >= 0)
                dp[j] = dp[j] + dp[j - coins[i]];

    return dp[amount];
}

int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << change(amount, coins) << endl;
    return 0;
}