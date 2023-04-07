#include <bits/stdc++.h>
using namespace std;

int equalSumIndex(int N, vector<int> A)
{
    int s1 = 0;
    for (int i = 0; i < N; i++)
        s1 += A[i];
    int s2 = A[N - 1];
    int i = 0;
    for (i = N - 1; i >= 0; i--)
    {
        if (s1 == s2)
            break;
        else
        {
            s1 -= A[i - 1];
            s2 += A[i];
        }
    }
    if (s1 == s2)
        return i + 1;
    return -1;
}

int main()
{
    // to find the first index in the array such that the sum of elements before it is equal to the sum of elements after it.
    // if it doesnt exist then return -1;
    int n = 5;
    vector<int> A = {1, 3, 5, 2, 2};

    cout << equalSumIndex(n, A) << endl;
    return 0;
}