#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0, j = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
        st.push(pushed[i]);
        while (st.size())
        {
            if (st.size() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            else
                break;
        }
    }
    if (st.size())
        return false;
    return true;
}

int main()
{
    // Check if the give pushed and popped sequence could have been the result of a sequence of push and pop operations on an initially empty stack,
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}