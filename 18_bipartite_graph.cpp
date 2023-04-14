#include <bits/stdc++.h>

using namespace std;

// using bfs
bool bfs(vector<vector<int>> adj, vector<int> &colored, int node)
{
    queue<int> q;
    q.push(node);
    colored[node] = 0;
    while (q.size())
    {
        int curr = q.front();
        q.pop();
        for (auto it : adj[curr])
        {
            if (colored[it] == -1)
            {
                colored[it] = abs(colored[curr] - 1);
                q.push(it);
            }
            else if (colored[it] == colored[curr])
                return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>> adj, vector<int> &colored, int node, int color)
{
    colored[node] = color;
    for (auto it : adj[node])
    {
        if (colored[it] == -1)
        {
            if (dfs(adj, colored, it, !color) == false)
                return false;
        }
        else if (colored[it] == colored[node])
            return false;
    }
    return true;
}

bool isBipartite(int V, vector<vector<int>> adj)
{
    vector<int> colored(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (colored[i] == -1)
        {
            // usinf BFS
            //  colored[i] = 0;
            //  if (!bfs(adj, colored, i))
            //      return false;

            // using DFS
            if (colored[i] == -1)
                if (dfs(adj, colored, i, 0) == false)
                    return false;
        }
    }
    return true;
}

int main()
{
    int V = 4;
    vector<vector<int>> adj;
    vector<int> v;
    v = {2, 3};
    adj.push_back(v);
    v.clear();
    v = {3};
    adj.push_back(v);
    v.clear();
    v = {0, 3};
    adj.push_back(v);
    v.clear();
    v = {0, 1, 2};
    adj.push_back(v);
    v.clear();
    cout << isBipartite(V, adj);
    return 0;
}
