#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    stack<string> st;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            str += s[i];
        else
        {
            st.push(str);
            str = "";
        }
    }
    if (str.length())
        st.push(str);
    str = "";
    while (st.size())
    {
        if (st.top() != "")
        {
            str += st.top();
            str += ' ';
        }
        st.pop();
    }
    str.pop_back();
    return str;
}

int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    return 0;
}