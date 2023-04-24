#include <bits/stdc++.h>

using namespace std;

int longestCommonSupersequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n + m - dp[n][m];
}

int main()
{
    // given two strings, find lcss
    // lcss is a string that has string1 and string2 as the subsequence
    // return the length of longest common supersequence
    string s1 = "aggtab";
    string s2 = "gxtxayb";
    cout << "Longest common supersequence:" << longestCommonSupersequence(s1, s2) << endl;
    return 0;
}