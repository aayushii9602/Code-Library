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
    vector<vector<int>> zigZagTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        int counter = 0;
        q.push(root);
        while (q.size())
        {
            int n = q.size();
            vector<int> v;
            while (n)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                v.push_back(temp->val);
                n--;
            }
            if (counter % 2 == 0)
                ans.push_back(v);
            else
            {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            counter++;
        }

        return ans;
    }
};

int main()
{
    // spiral traversal
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
    vector<vector<int>> ans = root->zigZagTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}