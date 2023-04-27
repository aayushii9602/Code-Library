#include <bits/stdc++.h>

using namespace std;

bool existAPath(vector<vector<int>> graph, int node1, int node2)
{
    vector<vector<int>> dp = graph;
    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    if (dp[node1][node2] == 1 && dp[node2][node1] == 1)
        return true;
    return false;
}

int main()
{
    // based on kleen's theorem
    //  transitive property algorithm
    //  to check if there exist a path  between any two nodes of a graph
    vector<vector<int>> graph = {{0, 1, 0, 0},
                                 {0, 0, 0, 1},
                                 {0, 0, 0, 0},
                                 {1, 0, 1, 0}};
    if (existAPath(graph, 0, 3))
        cout << "There exist a path\n";
    else
        cout << "No such oath exist\n";
    if (existAPath(graph, 0, 2))
        cout << "There exist a path\n";
    else
        cout << "No such path exist\n";
    return 0;
}