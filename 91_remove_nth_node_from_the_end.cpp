#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    int length(ListNode *head)
    {
        int l = 0;
        while (head != NULL)
        {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || n == 0)
            return head;
        int l = length(head);
        if (n == l)
        {
            ListNode *toDlt = head;
            ListNode *temp = head->next;
            // head->next=head->next->next;
            delete toDlt;
            return temp;
        }
        int k = l - n, count = 0;
        ListNode *temp = head;
        ListNode *ans = temp;
        while (count != k - 1)
        {
            count++;
            temp = temp->next;
        }
        ListNode *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
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
    int n = 4;
    ListNode *newHead = head->removeNthFromEnd(head, n);
    newHead->printList(newHead);
    return 0;
}