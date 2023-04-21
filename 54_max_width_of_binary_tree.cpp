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

    int maximumWidth(TreeNode *root)
    {
        int maxWidth = 0;
        if (root == NULL)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (q.size())
        {
            int n = q.size();
            int leftEnd = q.front().second;
            int rightEnd = q.back().second;
            maxWidth = max(maxWidth, rightEnd - leftEnd + 1);

            while (n)
            {
                TreeNode *temp = q.front().first;
                int index = q.front().second;
                n--;
                q.pop();
                if (temp->left)
                    q.push({temp->left, 2 * index + 1});
                if (temp->right)
                    q.push({temp->right, 2 * index + 2});
            }
        }
        return maxWidth;
    }
};
int main()
{
    TreeNode *r = new TreeNode(1);
    TreeNode *root = r;
    r->left = new TreeNode(3);
    r->right = new TreeNode(2);
    // r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(9);
    r->left->left = new TreeNode(5);
    r->left->right = new TreeNode(3);
    cout << root->maximumWidth(root) << endl;
    return 0;
}