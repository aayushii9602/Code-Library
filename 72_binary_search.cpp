#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int key)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    // array must be sorted
    // searching algorithm
    vector<int> arr = {3, 6, 8, 12, 14, 17, 25, 29, 31, 36, 42, 47, 53, 55, 62};
    // maximum comparism logn, n is the height of the tree.
    // worst case:O(logn)
    int key = 6;
    if (binarySearch(arr, key) != -1)
        cout << "index of " << key << " is " << binarySearch(arr, key);
    else
        cout << "Not found\n";
    return 0;
}