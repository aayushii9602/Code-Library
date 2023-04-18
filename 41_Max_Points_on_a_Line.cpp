#include <bits/stdc++.h>

using namespace std;
int maxPoints(vector<vector<int>> &points)
{
    if (points.size() < 3)
        return points.size();
    int finalans = 0;
    for (int i = 0; i < points.size(); i++)
    {
        map<double, int> m;
        int cnt = 1;
        for (int j = i + 1; j < points.size(); j++)
        {
            if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                cnt++;
            else if (points[i][0] == points[j][0])
                m[INT_MIN]++;
            else
            {
                double xslope = (double)points[i][0] - points[j][0];
                double yslope = (double)points[i][1] - points[j][1];
                double slope = yslope / xslope;
                m[slope]++;
            }
        }
        int ans = 0;
        for (auto it : m)
        {
            if (it.second > ans)
                ans = it.second;
        }
        ans += cnt;
        finalans = max(finalans, ans);
    }

    // if(ans!=INT_MIN)
    return finalans;
}

int main()
{
    // [ 3, 2 ], [ 5, 3 ], [ 4, 1 ], [ 2, 3 ], [ 1, 4 ];
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << maxPoints(points);
    return 0;
}