#include <bits/stdc++.h>

using namespace std;

int ans = 0;
long long toh(int N, char from, char to, char aux)
{
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        return 1;
    }
    ans += toh(N - 1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    ans += toh(N - 1, aux, to, from);
    return pow(2, N) - 1;
}

int main()
{
    int n = 4;
    int numberOfSteps = toh(n, 'A', 'B', 'C');
    cout << "Number of steps:" << numberOfSteps << endl;
    return 0;
}