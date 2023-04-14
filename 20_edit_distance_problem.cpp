#include <bits/stdc++.h>

using namespace std;

int editDistanceProblem(string src, string dest)
{
    int n = src.length();
    int m = dest.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (src[i - 1] == dest[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[n][m];
}

int main()
{
    // you can instert,delete or replace
    // return the minimum nomber of operations required to convert source string to destination string
    string src = "apiskal";
    string dest = "vishal";
    cout << editDistanceProblem(src, dest) << endl;
    return 0;
}
