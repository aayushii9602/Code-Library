#include <bits/stdc++.h>

using namespace std;
bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2)
        return false;
    sum /= 2;
    int dp[n + 1][sum + 1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (dp[i - 1][j] == true)
                dp[i][j] = true;
            else
            {
                if (arr[i - 1] > j)
                    dp[i][j] = false;
                else
                    dp[i][j] = dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    // to check whether it is possible to partition the array into two subsets with equal sum
    int arr[4] = {1, 5, 11, 5};
    int n = 4;
    if (equalSumPartition(arr, n))
        cout << "POSSIBLE\n";
    else
        cout << "NOT POSSIBLE\n";
    return 0;
}