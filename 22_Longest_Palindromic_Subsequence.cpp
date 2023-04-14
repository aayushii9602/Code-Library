#include <bits/stdc++.h>

using namespace std;

int longestPalindromeSubseq(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    string ans = "";
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // print the longest palindromic subsequence
    int i = n, j = n, k = dp[n][n];
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--;
            j--;
            k--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans << "\n";
    return dp[n][n];
}
int main()
{
    string s = "abcdafb";
    cout << longestPalindromeSubseq(s);
    return 0;
}
