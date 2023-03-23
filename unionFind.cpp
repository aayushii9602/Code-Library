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
int main()
{
    Disjoint ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "They have same ultimate parent\n";
    else
        cout << "they have different ultimate parent\n";
    ds.unionByRank(3, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "They belong to same connection\n";
    else
        cout << "they do not belong to same connevction/network\n";
    return 0;
}