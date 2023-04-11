#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *temp = lists[i];
            while (temp)
            {
                minheap.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *ans = new ListNode();
        ListNode *newHead = ans;
        while (minheap.size())
        {
            ListNode *temp = new ListNode(minheap.top());
            ans->next = temp;
            ans = ans->next;
            minheap.pop();
        }
        return newHead->next;
    }

    void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
        return;
    }
};

int main()
{
    ListNode *l1 = new ListNode(), *l2 = new ListNode(), *l3 = new ListNode(), *t1, *t2, *t3;
    t1 = l1, t2 = l2, t3 = l3;
    vector<int> v1 = {1, 3, 5, 7, 12}, v2 = {2, 9, 10}, v3 = {4, 6, 8, 11};
    for (int i = 0; i < v1.size(); i++)
    {
        ListNode *temp = new ListNode(v1[i]);
        l1->next = temp;
        l1 = l1->next;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        ListNode *temp = new ListNode(v2[i]);
        l2->next = temp;
        l2 = l2->next;
    }
    for (int i = 0; i < v3.size(); i++)
    {
        ListNode *temp = new ListNode(v3[i]);
        l3->next = temp;
        l3 = l3->next;
    }
    t1 = t1->next, t2 = t2->next, t3 = t3->next;
    vector<ListNode *> v = {t1, t2, t3};
    ListNode *newHead = newHead->mergeKLists(v);
    newHead->printList(newHead);

    return 0;
}