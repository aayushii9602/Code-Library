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
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    Disjoint ds(n);
    int cnt = 0;
    for (int i = 0; i < connections.size(); i++)
    {
        if (ds.findUltimateParent(connections[i][0]) == ds.findUltimateParent(connections[i][1]))
            cnt++;
        else
            ds.unionByRank(connections[i][0], connections[i][1]);
    }
    int parentCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findUltimateParent(i) == i)
            parentCnt++;
    }
    parentCnt--;
    if (cnt >= parentCnt)
        return parentCnt;
    return -1;
}
int main()
{
    int n = 4;
    vector<vector<int>> connection = {{0, 1},
                                      {0, 2},
                                      {1, 2}};
    cout << makeConnected(n, connection) << endl;
    connection = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    n = 6;
    cout << makeConnected(n, connection) << endl;
    return 0;
}