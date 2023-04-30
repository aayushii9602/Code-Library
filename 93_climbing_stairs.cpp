#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n)
{
    int dp[n + 1];

    for (int i = 0; i <= n; i++)
        dp[i] = 0;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}
int main()
{
    int n = 10;
    cout << "Number of distinct ways of climbing stair: " << climbStairs(n) << endl;

    return 0;
}