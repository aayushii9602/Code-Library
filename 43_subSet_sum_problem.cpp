#include <bits/stdc++.h>

using namespace std;

bool subsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // it is not possible to have sum 1,2,3... with 0 elements
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = false;
    // it is possible to have sum 0 with any number of elements, ie, en empty set
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
    }
    return dp[n][sum];
}

int main()
{
    // find if there exists a subste in array whose sum is eual to given sum
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << subsetSum(arr, sum) << endl;
    return 0;
}