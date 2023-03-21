#include <bits/stdc++.h>

using namespace std;

int knapsack(int W, vector<int> val, vector<int> weight)
{
    int N = val.size();
    int dp[N + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weight[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][W];
}

int main()
{
    int W = 3;
    vector<int> val = {1, 2, 3};
    vector<int> weight = {4, 5, 1};
    cout << knapsack(W, val, weight);
    return 0;
}