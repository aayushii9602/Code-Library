#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    // given coins array and sum
    // find the number of ways we can form sum using the coins array
    // we can use a coins[i] any number of time
    // unbounded dp
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    //{{1+1+1+1+1},{1+1+1+2},{1+1+3},{2+3},{1+2+2}}
    // 5 ways
    cout << coinChange(coins, sum) << endl;
    return 0;
}