#include <bits/stdc++.h>
#define inf INT_MAX / 2
using namespace std;

vector<vector<int>> allPairShortestPath(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<vector<int>> dp = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    return dp;
}

int main()
{
    // based on kleen's theorem
    // all pair shortest path
    // dynamic prpgramming

    vector<vector<int>> graph = {{0, inf, 3, inf},
                                 {2, 0, inf, inf},
                                 {inf, 7, 0, 1},
                                 {6, inf, inf, 0}};
    vector<vector<int>> shortestPath = allPairShortestPath(graph);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
            cout << shortestPath[i][j] << " ";
        cout << endl;
    }

    return 0;
}