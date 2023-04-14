#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> money)
{
    int n = money.size();

    vector<int> dp(n + 1, 0);
    dp[1] = money[0];
    for (int i = 2; i <= n; i++)
    {
        int rob = dp[i - 2] + money[i - 1];
        int doNotRob = dp[i - 1];
        dp[i] = max(rob, doNotRob);
    }
    return dp[n];
}

int main()
{
    // you cant rob two adjacent houses
    vector<int> money = {1, 2, 3, 1};
    cout << "max money: " << maxProfit(money) << endl;
    money = {2, 7, 9, 3, 1};
    cout << "max money: " << maxProfit(money) << endl;
    return 0;
}
