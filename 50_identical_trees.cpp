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

    bool isIdentical(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        else if (!root1 && root2)
            return false;
        else if (root1 && !root2)
            return false;
        else
        {
            if (root1->val == root2->val && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
                return true;
            return false;
        }
    }
};

int main()
{
    TreeNode *r1 = new TreeNode(1);
    TreeNode *root1 = r1;
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(3);
    r1->left->left = new TreeNode(4);
    r1->left->left->right = new TreeNode(5);
    r1->right->left = new TreeNode(6);

    TreeNode *r2 = new TreeNode(1);
    TreeNode *root2 = r2;
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(3);
    r2->left->left = new TreeNode(4);
    // r2->left->left->right = new TreeNode(5);
    r2->right->left = new TreeNode(6);
    cout << root1->isIdentical(root1, root2) << endl;
    return 0;
}