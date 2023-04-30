#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int size(Node *head)
{
    int x = 0;
    while (head != NULL)
    {
        x++;
        head = head->next;
    }
    return x;
}
bool isPalindrome(Node *head)
{
    int x = size(head);
    int v[x];
    int cnt = 0;
    if (x == 1)
        return true;
    while (head != NULL)
    {
        v[cnt] = head->data;
        cnt++;
        head = head->next;
    }
    int f = 0;
    for (int i = 0, j = x - 1; i < x - 1 && j > 0; i++, j--)
    {
        if (v[i] == v[j])
            f = 1;
        else
        {
            f = 0;
            break;
        }
    }
    if (f)
        return true;
    else
        return false;
}

int main()
{
    Node *h = new Node(0);
    Node *head = h;
    vector<int> v = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    for (int i = 0; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        h->next = temp;
        h = h->next;
    }
    head = head->next;
    cout << isPalindrome(head) << endl;
    return 0;
}