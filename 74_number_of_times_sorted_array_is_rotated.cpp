#include <bits/stdc++.h>

using namespace std;

int numberOfRotation(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int n = arr.size();
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid < high && arr[mid + 1] < arr[mid])
            return (mid + 1);
        if (mid > low && arr[mid] < arr[mid - 1])
            return mid;
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[high] >= arr[mid])
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<int> rotated = {15, 18, 2, 3, 6, 12};
    cout << numberOfRotation(rotated) << endl;
    rotated = {4, 5, 6, 7, 0, 1, 2};
    cout << numberOfRotation(rotated) << endl;
    return 0;
}