#include <bits/stdc++.h>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    int ans = -1;
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (M[a][b] == 1)
            st.push(b);
        else //(M[b][a]==1)
            st.push(a);
    }
    int k = st.top();

    for (int i = 0; i < n; i++)
    {
        if (i != k)
        {
            if (M[i][k] != 1 || M[k][i] != 0)
                return -1;
        }
    }

    return k;
}

int main()
{
    int n = 3;
    vector<vector<int>> v = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << celebrity(v, n) << endl;
    n = 2;
    v = {{0, 1},
         {1, 0}};
    cout << celebrity(v, n) << endl;

    return 0;
}