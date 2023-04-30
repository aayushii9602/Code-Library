#include <bits/stdc++.h>

using namespace std;

bool winnerOfGame(string c)
{
    vector<int> a, b;
    int acnt = 0, bcnt = 0;
    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] == 'A')
        {
            acnt++;
        }
        else
        {
            if (acnt > 0)
                a.push_back(acnt);
            acnt = 0;
        }
    }
    if (acnt > 0)
        a.push_back(acnt);
    acnt = 0;

    for (int i = 0; i < c.length(); i++)
    {
        if (c[i] == 'B')
        {
            bcnt++;
        }
        else
        {
            if (bcnt > 0)
                b.push_back(bcnt);
            bcnt = 0;
        }
    }
    if (bcnt > 0)
        b.push_back(bcnt);
    bcnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > 2)
        {
            acnt += a[i] - 2;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] > 2)
        {
            bcnt += b[i] - 2;
        }
    }
    if (acnt > bcnt)
        return true;
    return false;
}

int main()
{
    string color = "AAABABB";
    cout << winnerOfGame(color) << endl;
    return 0;
}