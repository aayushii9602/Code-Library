#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int dp[cost.size() + 1];
    for (int i = 0; i < cost.size() + 1; i++)
    {
        dp[i] = 0;
    }
    for (int i = 2; i <= cost.size(); i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    // for (int i = 0; i < cost.size() + 1; i++)
    //     cout << dp[i] << " ";
    return dp[cost.size()];
}

int main()
{
    // minimum cost to reach the top of the floor.
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "minimum cost to reach top floor is " << minCostClimbingStairs(cost) << endl;
    return 0;
}