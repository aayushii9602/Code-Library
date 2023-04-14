#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *even = new ListNode();
    ListNode *odd = new ListNode();
    int i = 0;
    ListNode *newE = even, *newO = odd;
    while (head)
    {
        ListNode *temp = new ListNode(head->val);
        if (i % 2 == 0)
        {
            even->next = temp;
            even = even->next;
        }
        else
        {
            odd->next = temp;
            odd = odd->next;
        }
        i++;
        head = head->next;
    }
    newE = newE->next;
    ListNode *ans = newE;
    while (newE->next)
    {
        newE = newE->next;
    }
    newO = newO->next;
    newE->next = newO;
    return ans;
}
int main()
{
    //  group all the nodes with odd indices together followed by the nodes with even indices
    vector<int> linkedList = {1, 2, 3, 4, 5};
    ListNode *ptr = new ListNode(linkedList[0]);
    ListNode *head = ptr;
    for (int i = 1; i < linkedList.size(); i++)
    {
        ListNode *temp = new ListNode(linkedList[i]);
        ptr->next = temp;
        ptr = ptr->next;
    }

    ListNode *newHead = oddEvenList(head);
    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
