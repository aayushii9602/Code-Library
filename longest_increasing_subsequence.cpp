#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int> v)
{
    vector<int> lis(v.size());
    // memset(lis, 1, sizeof(lis));
    for (int i = 0; i < lis.size(); i++)
        lis[i] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
                lis[i] = max(lis[j] + 1, lis[i]);
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main()
{
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << longestIncreasingSubsequence(v) << endl;
    v.clear();
    v = {0, 1, 0, 3, 2, 3};
    cout << longestIncreasingSubsequence(v) << endl;
    v.clear();
    v = {7, 7, 7, 7, 7, 7, 7};
    cout << longestIncreasingSubsequence(v) << endl;
    return 0;
}