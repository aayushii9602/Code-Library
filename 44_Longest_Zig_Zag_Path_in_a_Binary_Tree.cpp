#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rootL(TreeNode *root);

int rootR(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + rootL(root->left);
}

int rootL(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + rootR(root->right);
}
int longestZigZag(TreeNode *root)
{
    // // basically, if left node exist we tend to move towards the right of the left node. And vice-versa. Also it is not mandatory that the longest path is from the root, it can be from any other node too.
    if (root == NULL)
        return 0;
    int ans = max(rootL(root), rootR(root));
    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            ans = max(ans, rootR(temp->left));
        }
        if (temp->right)
        {
            q.push(temp->right);
            ans = max(ans, rootL(temp->right));
        }
    }
    return ans - 1;
}

int main()
{

    // longest ZigZag path contained in that tree.
    TreeNode *root = new TreeNode(1);
    TreeNode *r = root;
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);
    cout << longestZigZag(r);
    return 0;
}