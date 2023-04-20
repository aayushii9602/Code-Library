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

    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isHeightBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        if (abs(height(root->left) - height(root->right)) <= 1)
            return isHeightBalanced(root->left) && isHeightBalanced(root->right);
        return false;
    }

    pair<bool, int> optimisedBalanced(TreeNode *root)
    {
        pair<bool, int> ans;
        if (root == NULL)
        {
            ans.first = true;
            ans.second = 0;
            return ans;
        }
        pair<bool, int> leftTree = optimisedBalanced(root->left);
        pair<bool, int> rightTree = optimisedBalanced(root->right);

        if (leftTree.first && rightTree.first)
        {
            if (abs(leftTree.second - rightTree.second) <= 1)
            {
                ans.first = true;
                ans.second = max(leftTree.second, rightTree.second) + 1;
            }
            else
                ans.first = false;
        }
        // else
        //     ans.first = false;
        return ans;
    }
};

int main()
{
    TreeNode *r = new TreeNode(1);
    TreeNode *root = r;
    r->left = new TreeNode(1);
    r->right = new TreeNode(1);
    r->left->left = new TreeNode(1);
    // r->left->left->right = new TreeNode(1);
    r->right->left = new TreeNode(1);
    cout << root->isHeightBalanced(root) << endl;
    pair<bool, int> heightBalanced = root->optimisedBalanced(root);
    cout << heightBalanced.first << endl;
    return 0;
}