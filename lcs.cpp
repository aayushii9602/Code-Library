#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}

int main()
{
    // finding the length of longest common subsequence
    string s1 = "abcde", s2 = "ace";
    cout << "Length of longest common subsequence of strings " << s1 << " and " << s2 << " is " << longestCommonSubsequence(s1, s2) << endl;
    s1 = "abc", s2 = "abc";
    cout << "Length of longest common subsequence of strings " << s1 << " and " << s2 << " is " << longestCommonSubsequence(s1, s2) << endl;
    s1 = "abc", s2 = "def";
    cout << "Length of longest common subsequence of strings " << s1 << " and " << s2 << " is " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}