#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    int getCount(Node *root, int l, int h)
    {
        // your code goes here
        int ans = 0;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            if (temp->data >= l && temp->data <= h)
            {
                ans++;
            }
            if (temp->left)
                st.push(temp->left);
            if (temp->right)
                st.push(temp->right);
        }
        return ans;
    }
};
int main()
{
    int lowerBound = 1, upperBound = 5;
    Node *r = new Node(4);
    Node *root = r;
    r->left = new Node(6);
    r->right = new Node(1);
    r->left->left = new Node(2);
    r->left->left->right = new Node(10);
    r->right->left = new Node(5);
    cout << root->getCount(root, lowerBound, upperBound) << endl;
    return 0;
}