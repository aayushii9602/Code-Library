#include <bits/stdc++.h>

using namespace std;

class Disjoint
{
public:
    vector<int> parent, size;
    Disjoint(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findUltParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultParentU = findUltParent(u);
        int ultParentV = findUltParent(v);
        if (ultParentV == ultParentU)
            return;
        else if (size[ultParentU] < size[ultParentV])
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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // int number
        Disjoint ds(10000);
        pair<int, int> p = {-1, -1};
        for (int i = 0; i < edges.size(); i++)
        {
            if (ds.findUltParent(edges[i][0]) == ds.findUltParent(edges[i][1]))
            {
                p.first = edges[i][0];
                p.second = edges[i][1];
                continue;
            }
            else
            {
                ds.unionBySize(edges[i][0], edges[i][1]);
            }
        }
        vector<int> ans;
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
    }
};

int main()
{
    //  edge that can be removed so that the resulting graph is a tree of n nodes
    int n = 5;
    Disjoint ds(n);
    vector<vector<int>> edges = {{1, 2}, {3, 4}, {2, 3}, {1, 5}, {1, 4}};
    vector<int> redundant = ds.findRedundantConnection(edges);
    for (int i = 0; i < redundant.size(); i++)
        cout << redundant[i] << " ";
    cout << endl;
    return 0;
}