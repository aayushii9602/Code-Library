#include <bits/stdc++.h>

using namespace std;

void dfs(int n, map<int, vector<int>> adj, vector<bool> &visited)
{
    visited[n] = true;
    for (auto i : adj[n])
    {
        if (!visited[i])
            dfs(i, adj, visited);
    }
}

bool isSimilar(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            cnt++;
        if (cnt > 2)
            return false;
    }
    if (cnt == 2 || cnt == 0)
        return true;
    return false;
}
int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSimilar(strs[i], strs[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, adj, visited);
        }
    }
    return count;
}

int main()
{
    vector<string> strs = {"tars", "rats", "arts", "star"};
    cout << "Number of groups: " << numSimilarGroups(strs) << endl;
    return 0;
}