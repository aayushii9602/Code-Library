#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], int node, vector<int> &ans, vector<int> &visited)
{
    visited[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            dfs(adj, it, ans, visited);
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(0);
    adj[2].push_back(4);
    adj[4].push_back(2);
    vector<int> ans;
    vector<int> visited(V, 0);
    dfs(adj, 0, ans, visited);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}