#include <bits/stdc++.h>

using namespace std;

string nextLexicoPerm(string s)
{
    int n = s.length();
    int first = 0, second = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] < s[i + 1])
        {
            first = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] > first)
        {
            second = i;
            break;
        }
    }
    swap(s[first], s[second]);
    sort(s.begin() + first + 1, s.end());
    return s;
}

int main()
{
    // given a string , print next largest lexicographically string
    string s = "abcfed";
    string next = nextLexicoPerm(s);
    cout << next << endl;
    return 0;
}
