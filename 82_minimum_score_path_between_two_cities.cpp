#include <bits/stdc++.h>

using namespace std;

class Disjoint
{
    vector<int> rank, parent;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    // union by rank
    void unionByRank(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);
        if (ultParentU == ultParentV)
            return;
        if (rank[ultParentU] < rank[ultParentV])
            parent[ultParentU] = ultParentV;
        else if (rank[ultParentU] > rank[ultParentV])
            parent[ultParentV] = ultParentU;
        else
        {
            parent[ultParentV] = ultParentU;
            rank[ultParentU]++;
        }
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        Disjoint ds(n);
        int ans = INT_MAX;
        for (int i = 0; i < roads.size(); i++)
            ds.unionByRank(roads[i][0], roads[i][1]);
        for (int i = 0; i < roads.size(); i++)
        {
            if (ds.findUltimateParent(1) == ds.findUltimateParent(roads[i][0]) || ds.findUltimateParent(1) == ds.findUltimateParent(roads[i][1]))
                ans = min(ans, roads[i][2]);
        }
        return ans;
    }
};

int main()
{
    int n = 4;
    Disjoint ds(n);
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    cout << "path from 1 to " << n << " with minimum score would be " << ds.minScore(n, roads) << endl;
    return 0;
}