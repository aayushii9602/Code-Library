#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    bool check(TreeNode *r1, TreeNode *r2)
    {
        if ((r1 && !r2) || (r2 && !r1))
            return false;
        else if (!r1 && !r2)
            return true;
        if (r1->val == r2->val)
            return check(r1->left, r2->right) && check(r1->right, r2->left);
        else
            return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root->left, root->right);
    }
};

int main()
{
    TreeNode *r1 = new TreeNode(1);
    TreeNode *root1 = r1;
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(2);
    r1->left->left = new TreeNode(4);
    r1->left->right = new TreeNode(5);
    r1->right->left = new TreeNode(5);
    r1->right->right = new TreeNode(4);

    if (root1->isSymmetric(root1))
        cout << "Symmetric" << endl;
    else
        cout << "Not Symmetric\n";
    return 0;
}