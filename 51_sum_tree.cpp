#include <bits/stdc++.h>

using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }

    bool isSumTree(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
            return true;
        if (isSumTree(root->left) && isSumTree(root->right))
        {
            if (root->left->val + root->right->val == root->val)
                return true;
            else
                return false;
        }
        return false;
    }
};
int main()
{
    //  for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value
    // An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0.
    // A leaf node is also considered a Sum Tree.
    TreeNode *r = new TreeNode(20);
    TreeNode *root = r;
    r->left = new TreeNode(15);
    r->right = new TreeNode(5);
    r->left->left = new TreeNode(10);
    r->left->right = new TreeNode(5);
    r->right->left = new TreeNode(2);
    r->right->right = new TreeNode(3);
    //         20
    //      /       \
    //    15          5
    //    / \        /  \
    //   10  5      2    3
    cout << root->isSumTree(root);
    return 0;
}