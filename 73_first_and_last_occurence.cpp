#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int> &arr, int target)
{
    vector<int> ans;
    int l = 0, h = arr.size() - 1, mid;
    int firstIndex = -1, lastIndex = -1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == target)
        {
            firstIndex = mid;
            h = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    if (firstIndex == -1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    l = 0, h = arr.size() - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == target)
        {
            lastIndex = mid;
            l = mid + 1;
        }
        else if (arr[mid] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    ans.push_back(firstIndex);
    ans.push_back(lastIndex);

    return ans;
}

int main()
{
    //  the starting and ending position of a given target value.
    vector<int> arr = {1, 2, 3, 3, 5, 5, 5, 5, 6, 9, 10};
    vector<int> occurances = searchRange(arr, 5);
    cout << "First Occurance: " << occurances[0] << endl;
    cout << "Last Occurance: " << occurances[1] << endl;
    occurances = searchRange(arr, 4);
    cout << "First Occurance: " << occurances[0] << endl;
    cout << "Last Occurance: " << occurances[1] << endl;
    return 0;
}