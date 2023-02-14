#include <bits/stdc++.h>

using namespace std;

bool SubsetWithSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i <=n; i++)
        dp[i][0] = true; // there always exist a subset with sum=0 that is empty set

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
    // subset sum problem using dynamic programming
    int arr[6] = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    if (SubsetWithSum(arr, 6, sum))
        cout << "There exist a subset with the sum " << sum << endl;
    else
        cout << "There doesn't exist a subset with the sum " << sum << endl;

    int arr1[16] = {0, 0, 5, 5, 4, -1, 4, 9, 9, -1, 4, 3, 4, 8, 3, 8};
    sum = 4;
    if (SubsetWithSum(arr1, 16, sum))
        cout << "There exist a subset with the sum " << sum << endl;
    else
        cout << "There doesn't exist a subset with the sum " << sum << endl;
    return 0;
}
