#include <bits/stdc++.h>

using namespace std;

int solveTopDownApproach(vector<int> &s, int index, int time, vector<vector<int>> &dp)
{
    if (index == s.size())
        return 0;
    if (dp[index][time] != -1)
        return dp[index][time];
    int take = s[index] * (time + 1) + solveTopDownApproach(s, index + 1, time + 1, dp);
    int ignore = solveTopDownApproach(s, index + 1, time, dp);
    return dp[index][time] = max(take, ignore);
}

int maxSatisfaction(vector<int> &s)
{
    // dp solution
    // sort the array
    sort(s.begin(), s.end());
    // top-down dp solution
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    return solveTopDownApproach(s, 0, 0, dp);
}

int main()
{
    // Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
    // find maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
    // Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
    // Chef can cook any dish in 1 unit of time.
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}