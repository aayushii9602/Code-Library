#include <bits/stdc++.h>

using namespace std;

vector<int> maximum_in_right(vector<int> heights)
{
    vector<int> maxR;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = heights.size() - 1; i >= 0; i--)
    {
        pq.push(heights[i]);
        if (pq.size() > 1)
            pq.pop();
        maxR.push_back(pq.top());
    }
    reverse(maxR.begin(), maxR.end());
    return maxR;
}
vector<int> maximum_in_left(vector<int> heights)
{
    vector<int> maxL;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < heights.size(); i++)
    {
        pq.push(heights[i]);
        if (pq.size() > 1)
            pq.pop();
        maxL.push_back(pq.top());
    }
    return maxL;
}

int maximumRainWater(vector<int> heights)
{
    int ans = 0;
    vector<int> maxL, maxR, water;
    maxL = maximum_in_left(heights);
    maxR = maximum_in_right(heights);
    for (int i = 0; i < maxL.size(); i++)
        cout << maxL[i] << " ";
    cout << endl;
    for (int i = 0; i < maxR.size(); i++)
        cout << maxR[i] << " ";
    cout << endl;
    for (int i = 0; i < heights.size(); i++)
    {
        water.push_back(abs(min(maxL[i], maxR[i]) - heights[i]));
        ans += water[i];
    }
    return ans;
}

int main()
{

    // return the maximum amount of raain water that can be trapped in the buildings of givrn height.
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << maximumRainWater(heights);
    return 0;
}