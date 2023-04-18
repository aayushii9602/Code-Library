#include <bits/stdc++.h>

using namespace std;

class MinStack
{
public:
    stack<int> st;
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
    }

    void pop()
    {
        if (st.size())
            st.pop();
    }

    int top()
    {
        if (st.size())
            return st.top();
        return -1;
    }

    int getMin()
    {
        if (st.size())
        {
            stack<int> st2 = st;
            int ans = INT_MAX;
            while (st2.size())
            {
                ans = min(ans, st2.top());
                st2.pop();
            }
            return ans;
        }
        return -1;
    }
};

int main()
{
    MinStack st;
    st.push(0);
    st.push(1);
    st.push(3);
    st.push(-2);
    cout << "Min element:" << st.getMin() << endl;
    st.pop();
    cout << "Min element:" << st.getMin() << endl;
    st.pop();
    cout << "Min element:" << st.getMin() << endl;
    cout << "Min element:" << st.getMin() << endl;
    st.pop();
    st.pop();
    return 0;
}