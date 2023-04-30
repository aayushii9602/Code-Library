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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long long> ans;
        long long value = 0;
        if (root == NULL)
            return value;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<long long> v;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                v.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (!q.empty())
            {
                q.push(NULL);
                value = 0;
                while (!v.empty())
                {
                    value += v[v.size() - 1];
                    v.pop_back();
                }
                ans.push_back(value);
            }
        }
        value = 0;
        while (!v.empty())
        {
            value += v[v.size() - 1];
            v.pop_back();
        }
        ans.push_back(value);
        sort(ans.begin(), ans.end());
        // for (long long i = 0; i < ans.size(); i++)
        //     cout << ans[i] << " ";
        if (k > ans.size())
            return -1;
        // cout<<endl;
        return ans[ans.size() - k];
    }
};

int main()
{
    //  kth largest level sum in the tree
    TreeNode *r = new TreeNode(1);
    TreeNode *root = r;
    r->left = new TreeNode(9);
    r->right = new TreeNode(2);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(7);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(3);
    int k = 2;
    cout << root->kthLargestLevelSum(root, k);
    return 0;
}