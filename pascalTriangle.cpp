#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> PascalTriangle(int rows)
{
    vector<vector<int>> ans;
    vector<int> v;
    v.push_back(1);
    ans.push_back(v);
    if (rows == 1)
        return ans;
    v.push_back(1);
    ans.push_back(v);
    if (rows == 2)
        return ans;
    for (int i = 3; i <= rows; i++)
    {
        vector<int> vec;
        vec.push_back(1);
        for (int j = 1; j < ans[ans.size() - 1].size(); j++)
        {
            vec.push_back(ans[ans.size() - 1][j] + ans[ans.size() - 1][j - 1]);
        }
        vec.push_back(1);
        ans.push_back(vec);
    }
    return ans;
}

int main()
{
    // a triangular arrangement of numbers that gives the coefficients in the expansion of any binomial expression
    int rows = 5;
    vector<vector<int>> v = PascalTriangle(rows);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}