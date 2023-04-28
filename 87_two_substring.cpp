#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

int main()
{
    ll t = 1;
    for (ll tc = 0; tc < t; tc++)
    {
        // to determine if the given string s contains two non-overlapping substrings "AB" and "BA" (the substrings can go in any order).
        string s;
        // cin >> s;
        s = "BACFAB";
        map<int, int>
            m;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B')
            {
                m[i]++;
                m[i + 1]++;
                break;
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'A' && m[i] != 1 && m[i + 1] != 1)
            {
                m[i]++;
                m[i + 1]++;
                break;
            }
        }
        map<int, int> m1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == 'B' && s[i + 1] == 'A')
            {
                m1[i]++;
                m1[i + 1]++;
                break;
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && m1[i] != 1 && m1[i + 1] != 1)
            {
                m1[i]++;
                m1[i + 1]++;
                break;
            }
        }
        if (m.size() >= 4 || m1.size() >= 4)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}