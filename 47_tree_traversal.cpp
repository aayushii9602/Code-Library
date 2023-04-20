#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    void inOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }

    void preOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        cout << root->val << " ";
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        cout << root->val << " ";
    }
};

int main()
{
    TreeNode *r = new TreeNode(1);
    TreeNode *root = r;
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);
    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(7);
    cout << "Inorder: ";
    root->inOrderTraversal(root);
    cout << endl;
    cout << "Preorder: ";
    root->preOrderTraversal(root);
    cout << endl;
    cout << "Postorder: ";
    root->postOrderTraversal(root);
    cout << endl;
    return 0;
}