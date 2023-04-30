#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSize)
{
    map<int, int> m;
    for (int i = 0; i < groupSize.size(); i++)
    {
        if (m[groupSize[i]] == 0)
            m[groupSize[i]] = 1;
        else
            m[groupSize[i]]++;
    }
    vector<vector<int>> v;
    for (auto it : m)
    {
        vector<int> x;
        for (int i = 0; i < groupSize.size(); i++)
        {
            if (groupSize[i] == it.first)
                x.push_back(i);
            if (x.size() == it.first)
            {
                v.push_back(x);
                while (!x.empty())
                {
                    x.pop_back();
                }
            }
        }
        if (x.size() != it.first && x.size() != 0)
            v.push_back(x);
    }
    return v;
}

int main()
{
    vector<int> groupSize = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int>> ans = groupThePeople(groupSize);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}