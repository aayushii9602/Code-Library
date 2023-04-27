#include <bits/stdc++.h>

using namespace std;

class Item
{
public:
    int value;
    int weight;
    static bool getmax(class Item first, class Item second)
    {
        double x = 1.0 * first.value / first.weight;
        double y = 1.0 * second.value / second.weight;
        return x > y;
    }

    double fractionalKnapsack(int W, vector<Item> arr, int N)
    {
        sort(arr.begin(), arr.end(), getmax);

        double ans = 0.0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i].weight <= W)
            {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                ans += arr[i].value * (1.0 * W / arr[i].weight);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    int W = 50, N = 3;
    vector<Item> itemArray;
    Item i;
    i.value = 60;
    i.weight = 10;
    itemArray.push_back(i);
    i.value = 100;
    i.weight = 20;
    itemArray.push_back(i);
    i.value = 120;
    i.weight = 30;
    itemArray.push_back(i);
    cout << i.fractionalKnapsack(W, itemArray, N) << endl;

    return 0;
}