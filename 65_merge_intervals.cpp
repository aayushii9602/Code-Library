#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &inter)
{
    vector<vector<int>> ans;
    int n = inter.size();
    sort(inter.begin(), inter.end());
    vector<int> v = inter[0];
    for (int i = 0; i < n; i++)
    {
        if (inter[i][0] <= v[1])
            v[1] = max(v[1], inter[i][1]);
        else
        {
            ans.push_back(v);
            v = inter[i];
        }
    }
    ans.push_back(v);
    return ans;
}

int main()
{
    // merge all overlapping intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 8}, {10, 15}};
    vector<vector<int>> mergedInterval = merge(intervals);
    for (int i = 0; i < mergedInterval.size(); i++)
        cout << mergedInterval[i][0] << " " << mergedInterval[i][1] << endl;
    return 0;
}