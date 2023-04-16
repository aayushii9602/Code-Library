#include <bits/stdc++.h>

using namespace std;
vector<int> stockSpan(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        while (st.size() && v[st.top()] <= v[i])
            st.pop();
        if (st.empty())
        {
            ans.push_back(i + 1);
            // storing the index
            st.push(i);
        }
        else
        {
            ans.push_back(i - st.top());
            st.push(i);
        }
    }
    return ans;
}
int main()
{

    vector<int> v = {68, 735, 101, 770, 525, 279, 559, 563, 465, 106, 146, 82, 28, 362, 492, 596, 743, 28, 637, 392, 205, 703, 154, 293, 383, 622, 317, 519, 696, 648, 127, 372, 339, 270, 713, 68, 700, 236, 295, 704, 612, 123};
    vector<int> ans = stockSpan(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    v = {100, 80, 60, 70, 60, 75, 85};
    ans = stockSpan(v);
    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
