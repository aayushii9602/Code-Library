#include <bits/stdc++.h>

using namespace std;
vector<int> adj[50000];
vector<bool> visited;
set<pair<int, int>> s;
int minReorder(int n, vector<vector<int>> &connections)
{
    visited.resize(50000, false);
    for (int i = 0; i < connections.size(); i++)
    {
        s.insert({connections[i][0], connections[i][1]}); // actual connections

        // create a bidirectional , in order to traverse through the entire graph.
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    queue<int> q;
    q.push(0);
    int ans = 0;
    while (q.size())
    {
        int node = q.front();
        q.pop();

        // check if the node is visited or not
        if (visited[node] == false)
        {
            visited[node] = true;
            for (int i = 0; i < adj[node].size(); i++)
            {
                // push the child of the parent node
                q.push(adj[node][i]);

                // check if the child is visited or not, if not then check if there is a path from child to parent or parent to child.
                //  if there exits a path from parent to child then ans++(all the nodes should direct toward their parent)
                if (visited[adj[node][i]] == false && s.count({node, adj[node][i]}) == 1)
                    ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << "minimum number of edges  to be reorderd: " << minReorder(n, connections);
    return 0;
}