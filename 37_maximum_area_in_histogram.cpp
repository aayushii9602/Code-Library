#include <bits/stdc++.h>

using namespace std;

vector<int> nearest_smaller_to_left(vector<int> hist)
{
    vector<int> ans;
    stack<int> st;
    int n = hist.size();
    for (int i = 0; i < n; i++)
    {
        while (st.size() && hist[st.top()] >= hist[i])
            st.pop();
        if (st.size())
            ans.push_back(i - st.top());
        else
            ans.push_back(i + 1);
        st.push(i);
    }
    return ans;
}
vector<int> nearest_smaller_to_right(vector<int> hist)
{
    vector<int> ans;
    stack<int> st;
    int n = hist.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && hist[st.top()] >= hist[i])
            st.pop();
        if (st.empty())
            ans.push_back(n - i);
        else
            ans.push_back(abs(st.top() - i));
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> hist = {2, 1, 5, 6, 2, 3};
    hist = {2, 4};
    vector<int> left = nearest_smaller_to_left(hist);
    vector<int> right = nearest_smaller_to_right(hist);
    // for (int i = 0; i < left.size(); i++)
    //     cout << left[i] << " ";
    // cout << endl;
    // for (int i = 0; i < right.size(); i++)
    //     cout << right[i] << " ";
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < hist.size(); i++)
    {
        ans = max(ans, (left[i] + right[i] - 1) * hist[i]);
    }
    cout << ans << endl;
    return 0;
}