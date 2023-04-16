#include <bits/stdc++.h>

using namespace std;

vector<int> nearest_greater_to_left(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (st.size() && st.top() < v[i])
            st.pop();
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(v[i]);
        }
        else
        {
            ans.push_back(st.top());
            st.push(v[i]);
        }
    }
    return ans;
}

vector<int> nearest_greater_to_right(vector<int> v)
{
    int n = v.size();
    stack<int> st;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() && st.top() < v[i])
            st.pop();
        if (!st.size())
        {
            ans.push_back(-1);
            st.push(v[i]);
        }
        else
        {
            ans.push_back(st.top());
            st.push(v[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nearest_smaller_to_left(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (st.size() && st.top() > v[i])
            st.pop();
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(v[i]);
        }
        else
        {
            ans.push_back(st.top());
            st.push(v[i]);
        }
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
        while (st.size() && st.top() > v[i])
            st.pop();
        if (st.size())
            ans.push_back(st.top());
        else
            ans.push_back(-1);
        st.push(v[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 2, 4};

    vector<int> ans = nearest_greater_to_left(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    ans = nearest_greater_to_right(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    v = {4, 5, 2, 10, 8};
    ans = nearest_smaller_to_left(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    ans = nearest_smaller_to_right(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
