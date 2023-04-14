#include <bits/stdc++.h>

using namespace std;

class Disjoint
{
    vector<int> rank, parent, size;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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

    // union by size
    // we can keep how many nodes are there in a network
    void unionBySize(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);
        if (ultParentU == ultParentV)
            return;
        else if (size[ultParentU < size[ultParentV]])
        {
            parent[ultParentU] = ultParentV;
            size[ultParentV] += size[ultParentU];
        }
        else
        {
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV];
        }
    }
};
int main()
{
    Disjoint ds(7);
    // union by rank
    //  ds.unionByRank(1, 2);
    //  ds.unionByRank(2, 3);
    //  ds.unionByRank(4, 5);
    //  ds.unionByRank(6, 7);
    //  ds.unionByRank(5, 6);

    // union by size
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "They belong to same connection\n";
    else
        cout << "They do not belong to same connevction/network\n";
    ds.unionByRank(3, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
        cout << "They belong to same connection\n";
    else
        cout << "They do not belong to same connevction/network\n";
    return 0;
}
