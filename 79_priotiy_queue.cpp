#include <bits/stdc++.h>

using namespace std;

int main()
{
    // MAX HEAP
    // USE MAX HEAP WHEN YOU HAVE TO FIND KTH SMALLEST ELEMENT
    priority_queue<int> maxheap;
    maxheap.push(9);
    maxheap.push(19);
    maxheap.push(2);
    maxheap.push(6);
    maxheap.push(0);
    maxheap.push(23);
    while (maxheap.size())
    {
        int x = maxheap.top();
        maxheap.pop();
        cout << x << " ";
    }
    cout << endl;

    // MIN HEAP
    // USE MIN HEAP WHEN YOU HAVE TO FIND KTH LARGEST ELEMENT

    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(9);
    minheap.push(19);
    minheap.push(2);
    minheap.push(6);
    minheap.push(0);
    minheap.push(23);

    while (minheap.size())
    {
        int x = minheap.top();
        minheap.pop();
        cout << x << " ";
    }
    cout << endl;

    // find kth LARGEST element from the given array
    //  can be done using sorting , but it can be done in minimum nlogn complexity
    //  but by using heap it can solved in nlogk complexity

    vector<int> v = {2, 38, 1, 90, 22, 8, 44, 21, 34, 93};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < v.size(); i++)
    {
        if (heap.size() < k)
            heap.push(v[i]);
        else
        {
            heap.push(v[i]);
            heap.pop();
        }
    }
    cout << "kth LARGEST element " << heap.top() << endl;

    // find kth SMALLEST element from the given array

    vector<int> v1 = {2, 38, 1, 90, 22, 8, 44, 21, 34, 93};
    int k1 = 3;
    priority_queue<int> heap1;
    for (int i = 0; i < v1.size(); i++)
    {
        heap1.push(v1[i]);
        if (heap1.size() <= k1)
            continue;
        else
            heap1.pop();
    }
    cout << "kth SMALLEST element from the given array:";
    cout << heap1.top() << endl;

    return 0;
}