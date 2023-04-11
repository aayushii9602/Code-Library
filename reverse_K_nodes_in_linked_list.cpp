#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    int length(ListNode *head)
    {
        int l = 0;
        while (head)
        {
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int l = length(head);
        if (!head || !head->next || l < k)
            return head;
        ListNode *curr = head, *prev = NULL, *nex;
        int count = 0;
        while (curr && count < k)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }
        ListNode *node = reverseKGroup(curr, k);
        ListNode *ans = prev;
        while (prev->next)
        {
            prev = prev->next;
        }
        prev->next = node;
        return ans;
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
    // everse the nodes of the list k at a time,
    ListNode *h = new ListNode(0);
    ListNode *head = h;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < v.size(); i++)
    {
        ListNode *temp = new ListNode(v[i]);
        h->next = temp;
        h = h->next;
    }
    head = head->next;
    head->printList(head);
    int k = 3;
    ListNode *newHead = head->reverseKGroup(head, k);
    newHead->printList(newHead);
    return 0;
}