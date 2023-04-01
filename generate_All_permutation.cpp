#include <bits/stdc++.h>

using namespace std;

void premutation(int index, string s, vector<string> &ans)
{
    if (index >= s.length())
    {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        premutation(index + 1, s, ans);
        swap(s[i], s[index]);
    }
}

int main()
{
    // given a string generate all possible permutation
    string s = "abcd";
    vector<string> ans;
    premutation(0, s, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << ":" << ans[i] << endl;
    }
    return 0;
}