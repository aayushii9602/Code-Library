#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertatatail(node *&head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteathead(node *&head)
{
    node*todelt=head;
    head=head->next;
    head->prev=NULL;
    delete todelt;
}

void deleteatpos(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteathead(head);
    }
    node *temp = head;
    for (int i = 2; i <= pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    node *todelete = temp;
    temp->prev->next = temp->next;
    if (temp != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete todelete;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    for (int i = 2; i <= 10; i++)
    {
        insertatatail(head, i);
    }
    display(head);
    insertathead(head, 1);
    display(head);
    deleteatpos(head, 2);
    display(head);
}
