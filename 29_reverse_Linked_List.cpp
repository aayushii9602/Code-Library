#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }

    ListNode *reverseLinkedListIterative(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nexPointer;

        while (curr)
        {
            nexPointer = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexPointer;
        }
        return prev;
    }

    ListNode *reverseLinkedListRecursive(ListNode *head)
    {
        // base case
        if (!head || !head->next)
            return head;
        ListNode *newHead = reverseLinkedListRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
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

    // ListNode *newHead = head->reverseLinkedListIterative(head);
    // newHead->printList(newHead);

    ListNode *newHead1 = head->reverseLinkedListRecursive(head);
    newHead1->printList(newHead1);

    return 0;
}
