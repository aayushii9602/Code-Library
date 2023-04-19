#include <bits/stdc++.h>

using namespace std;

bool equalSumPartition(vector<int> arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2)
        return false;
    sum /= 2;
    int n = arr.size();
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    // divide the array into two subset such the sum of elements of both the subsets is equal
    // return truenor false
    vector<int> arr = {1, 2, 3, 5};
    cout << equalSumPartition(arr) << endl;
    return 0;
}