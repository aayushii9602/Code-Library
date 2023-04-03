#include <bits/stdc++.h>

using namespace std;

bool bfsDetectCycle(int node, vector<vector<int>> adj, vector<int> &visited)
{
    visited[node] = true;
    queue<pair<int, int>> q;

    q.push({node, -1});
    while (q.size())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                q.push({it, node});
                visited[it] = 1;
            }
            else if (parent != it)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> adj)
{
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (bfsDetectCycle(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj;
    vector<int> v = {1};
    adj.push_back(v);
    v.clear();
    v = {0, 2, 5};
    adj.push_back(v);
    v.clear();
    v = {1, 3};
    adj.push_back(v);
    v.clear();
    v = {2, 4};
    adj.push_back(v);
    v.clear();
    v = {3};
    adj.push_back(v);
    v.clear();
    v = {1};
    adj.push_back(v);
    cout << isCycle(V, adj) << endl;
    return 0;
}