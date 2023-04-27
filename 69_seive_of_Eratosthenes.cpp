#include <bits/stdc++.h>

using namespace std;

void printPrimes(int n)
{
    cout << "prime numbers less than or equal to " << n << " : ";
    vector<bool> seive(n + 1, true);
    seive[0] = false;
    seive[1] = false;
    for (long long int i = 0; i <= n; i++)
    {
        if (seive[i] == true)
        {
            cout << i << " ";
            for (long long int j = i * i; j <= n; j += i)
                seive[j] = false;
        }
    }
    cout << endl;
}

int main()
{
    printPrimes(15);
    printPrimes(99);
    return 0;
}