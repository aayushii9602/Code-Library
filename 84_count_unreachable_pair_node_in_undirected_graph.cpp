#include <bits/stdc++.h>

using namespace std;

class DisJoint
{
public:
    vector<int> rank, parent;
    DisJoint(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int ultimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = ultimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultParentU = ultimateParent(u);
        int ultParentV = ultimateParent(v);
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

long long countPairs(int n, vector<vector<int>> &edges)
{
    long long ans = 0;
    DisJoint ds(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        if (ds.ultimateParent(edges[i][0]) == ds.ultimateParent(edges[i][1]))
            continue;
        else
        {
            if (edges[i][1] < edges[i][0])
                ds.unionByRank(edges[i][1], edges[i][0]);
            else
                ds.unionByRank(edges[i][0], edges[i][1]);
        }
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        ds.parent[i] = ds.ultimateParent(i);
        if (m[ds.parent[i]] == 0)
            m[ds.parent[i]] = 1;
        else
            m[ds.parent[i]]++;
    }
    vector<int> v;
    if (m.size() == 1)
        return 0;
    for (auto it : m)
        v.push_back(it.second);
    long long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += (sum * v[i]);
        sum += v[i];
    }
    return ans;
}
int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    cout << "number of nodes that are unreachable from each other :" << countPairs(n, edges) << endl;
    return 0;
}