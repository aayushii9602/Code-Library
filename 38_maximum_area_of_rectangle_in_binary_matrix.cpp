#include <bits/stdc++.h>

using namespace std;

vector<int> nearest_smaller_to_left(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();
        if (st.size())
            ans.push_back(i - st.top());
        else
            ans.push_back(i + 1);
        st.push(i);
    }
    return ans;
}
vector<int> nearest_smaller_to_right(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && v[st.top()] >= v[i])
            st.pop();
        if (st.size())
            ans.push_back(abs(i - st.top()));
        else
            ans.push_back(n - i);
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int maxiHistArea(vector<int> v)
{
    int ans = 0;
    vector<int> smallerleft = nearest_smaller_to_left(v);
    vector<int> smallerRight = nearest_smaller_to_right(v);
    // for (int i = 0; i < smallerleft.size(); i++)
    //     cout << smallerleft[i] << " ";
    // cout << endl;
    // for (int i = 0; i < smallerRight.size(); i++)
    //     cout << smallerRight[i] << " ";
    // cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, (smallerleft[i] + smallerRight[i] - 1) * v[i]);
    }
    return ans;
}

int maximalSquare(vector<string> matrix)
{
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            for (int k = i; k >= 0; k--)
            {
                if (matrix[k][j] == '1')
                    cnt++;
                else
                    break;
            }
            v.push_back(cnt);
        }
        ans = max(ans, maxiHistArea(v));
    }
    return ans;
}

int main()
{
    vector<string> histogram = {"111", "101"};
    cout << maximalSquare(histogram);
    return 0;
}