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

int findMST(vector<vector<int>> adj, int V)
{
    Disjoint ds(V);
    vector<pair<int, pair<int, int>>> vec;
    vector<pair<int, int>> edges;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] != 0)
                vec.push_back({adj[i][j], {i, j}});
        }
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (ds.findUltimateParent(vec[i].second.first) == ds.findUltimateParent(vec[i].second.second))
            continue;
        else
        {
            ans += vec[i].first;
            ds.unionBySize(vec[i].second.first, vec[i].second.second);
            edges.push_back({vec[i].second.first, vec[i].second.second});
        }
    }
    cout << "edges in MST are:\n";
    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    return ans;
}
int main()
{

    vector<vector<int>> adj;
    vector<int> v;
    int vertices = 5;
    v = {0, 1, 6, 2, 1};
    adj.push_back(v);
    v.clear();
    v = {1, 0, 4, 0, 0};
    adj.push_back(v);
    v.clear();
    v = {6, 4, 0, 3, 0};
    adj.push_back(v);
    v.clear();
    v = {2, 0, 3, 0, 3};
    adj.push_back(v);
    v.clear();
    v = {1, 0, 0, 3, 0};
    adj.push_back(v);
    v.clear();
    // for (int i = 0; i < vertices; i++)
    // {
    //     for (int j = 0; j < vertices; j++)
    //         cout << adj[i][j] << " ";
    //     cout << endl;
    // }
    cout << findMST(adj, vertices);
    return 0;
}