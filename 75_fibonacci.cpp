#include <bits/stdc++.h>

using namespace std;

int nthFib(int n)
{
    int v[40];
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i < 40; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
}

int nthTribonacci(int n)
{
    vector<int> v(38, 0);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i < 38; i++)
    {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }
    return v[n];
}

int main()
{
    int n = 5;
    cout << n << "th fibonacci number is " << nthFib(n) << endl;
    cout << n << "th Tribonacci number is " << nthTribonacci(n) << endl;
    return 0;
}