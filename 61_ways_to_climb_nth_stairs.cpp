#include <bits/stdc++.h>

using namespace std;

int countWays(int n)
{
    int mod = 1000000007;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    return dp[n];
}

int main()
{
    int n = 10;
    cout << countWays(n) << endl;
    n = 99;
    cout << countWays(n) << endl;
    n = 0;
    cout << countWays(n) << endl;
    return 0;
}