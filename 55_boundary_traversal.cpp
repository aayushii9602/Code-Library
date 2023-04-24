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
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    void leftTraversal(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        ans.push_back(root->data);
        if (root->left)
            leftTraversal(root->left, ans);
        else
            leftTraversal(root->right, ans);
    }

    void leafTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        else if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
    void rightTraversal(Node *root, vector<int> &ans)
    {
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
        if (root->right)
            rightTraversal(root->right, ans);
        else
            rightTraversal(root->left, ans);
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        ans.push_back(root->data);
        leftTraversal(root->left, ans);
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        rightTraversal(root->right, ans);
        return ans;
    }
};
int main()
{
    Node *r = new Node(1);
    Node *root = r;
    r->left = new Node(3);
    r->right = new Node(2);
    r->right->left = new Node(4);
    r->right->right = new Node(9);
    r->left->left = new Node(5);
    vector<int> b = root->boundary(root);
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}