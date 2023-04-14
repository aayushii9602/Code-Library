#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVisited, int node)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            visited[it] = 1;
            pathVisited[it] = 1;
            if (dfs(adj, visited, pathVisited, it) == true)
                return true;
            else
                pathVisited[it] = 0;
        }
        else if (visited[it] == 1 && pathVisited[it] == 1)
            return true;
    }
    pathVisited[node] = 0;
    return false;
}

bool detectCycle(vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVisited)
{
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(adj, visited, pathVisited, i) == true)
                return true;
        }
        else if (visited[i] && pathVisited[i])
            return true;
    }
    return false;
}

int main()
{
    int V = 4;
    vector<int> visited(V, 0), pathVisited(V, 0);
    vector<vector<int>> adj;
    vector<int> v;
    v = {};
    adj.push_back(v);
    v = {1};
    adj.push_back(v);
    v.clear();
    v = {2};
    adj.push_back(v);
    v.clear();
    v = {3};
    adj.push_back(v);
    v.clear();
    v = {3};
    adj.push_back(v);
    v.clear();
    cout << detectCycle(adj, visited, pathVisited);
    return 0;
}
