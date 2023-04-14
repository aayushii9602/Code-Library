#include <bits/stdc++.h>

using namespace std;

int maximumSubarraySum(vector<int> v)
{
    int tempSum = 0, maxSum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        tempSum += v[i];
        if (tempSum < 0)
            tempSum = 0;
        maxSum = max(maxSum, tempSum);
    }
    return maxSum;
}

int main()
{
    // find the maximum subarray sum
    // when all the elements of the array are negative the return the smallest element of the array
    // when all the elements of the array are negative the return the sum of the entire array.
    // when there is a combination of both then kadane's algorithm is the best approach so far.
    // dynamic window size
    vector<int> v{-2, -6, 8, -3, -2, 10, -1, 4};
    cout << maximumSubarraySum(v) << endl;
    v.clear();
    v = {5, 4, -1, 7, 8};
    cout << maximumSubarraySum(v) << endl;
    return 0;
}
