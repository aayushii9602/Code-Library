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

    int diameter(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);
        int diameter = height(root->left) + height(root->right) + 1;
        return max(leftDiameter, max(rightDiameter, diameter));
    }

    pair<int, int> optimisedDiameter(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p;
            p.first = 0,
            p.second = 0;
            return p;
        }

        pair<int, int> left = optimisedDiameter(root->left);
        pair<int, int> right = optimisedDiameter(root->right);
        int leftDiameter = left.first;
        int rightDiameter = right.first;
        int diameter = left.second + right.second + 1;
        pair<int, int> ans;
        ans.first = max(leftDiameter, max(rightDiameter, diameter));
        ans.second = max(left.second, right.second) + 1;
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
    r->left->left->right = new TreeNode(1);
    r->right->left = new TreeNode(1);
    cout << root->diameter(root) << endl;

    pair<int, int> p = root->optimisedDiameter(root); // pair<diameter,height>
    cout << p.first << endl;

    return 0;
}