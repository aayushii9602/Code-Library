#include <bits/stdc++.h>

using namespace std;

void solve(int index, int sum, vector<int> &ans, vector<int> arr, vector<vector<int>> &ansArray)
{
    if (index == arr.size())
    {
        if (sum == 0)
        {
            ansArray.push_back(ans);
        }
        return;
    }
    if (arr[index] <= sum)
    {
        ans.push_back(arr[index]);
        solve(index, sum - arr[index], ans, arr, ansArray);
        ans.pop_back();
    }
    solve(index + 1, sum, ans, arr, ansArray);
}
vector<vector<int>> combinationSum(vector<int> &arr, int sum)
{
    vector<vector<int>> ansArray;
    vector<int> ans;
    solve(0, sum, ans, arr, ansArray);
    return ansArray;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int sum = 7;
    vector<vector<int>> combinations = combinationSum(arr, sum);
    for (int i = 0; i < combinations.size(); i++)
    {
        for (int j = 0; j < combinations[i].size(); j++)
            cout << combinations[i][j] << " ";
        cout << endl;
    }
    return 0;
}