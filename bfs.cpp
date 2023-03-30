#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> ans;
    vector<int> visited(V, 0);
    q.push(0);
    visited[0] = 1;
    while (q.size())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (visited[it] == 0)
                q.push(it);
        }
    }
    return ans;
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
    vector<int> ans = bfs(V, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}