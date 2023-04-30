#include <bits/stdc++.h>

using namespace std;

class DataStream
{
public:
    int value, k;
    vector<int> v;
    int front = 0;
    map<int, int> m;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }

    bool consec(int num)
    {
        if (m[num] == 0)
            m[num] = 1;
        else
            m[num]++;
        v.push_back(num);
        if (v.size() - front < k)
            return false;
        if (v.size() - front > k)
        {
            m[v[front]] -= 1;
            front++;
        }
        if (m[value] == k)
            return true;
        return false;
    }
};

int main()
{
    DataStream ds(4, 3);
    cout << ds.consec(4) << "\n";
    cout << ds.consec(4) << "\n";
    cout << ds.consec(4) << "\n";
    cout << ds.consec(3) << "\n";
    return 0;
}