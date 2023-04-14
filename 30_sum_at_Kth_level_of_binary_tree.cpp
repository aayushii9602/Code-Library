#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }

    int sumAtKthLevel(TreeNode *root, int k)
    {
        // base case
        if (root == NULL)
            return -1;

        // using queue
        queue<TreeNode *> q;
        int sum = 0, level = 0;
        q.push(root);
        q.push(NULL);
        while (q.size())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp)
            {
                if (level == k)
                    sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (q.size())
            {
                level++;
                q.push(NULL);
            }
        }
        return sum;
    }

    int maximumLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        int sum = 0, level = 0, maxSum = INT_MIN, ansLevel = 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (q.size())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp)
            {
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if (q.size())
            {
                q.push(NULL);
                level++;
                if (maxSum < sum)
                {
                    maxSum = sum;
                    ansLevel = level;
                }
                sum = 0;
            }
        }
        if (maxSum < sum)
        {
            maxSum = sum;
            ansLevel = level;
        }
        return sum;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    //      5       <- 0th level(5)
    //    /   \   
    //   3     7    <- 1st level(10)
    //  / \   /
    // 2   4  6     <- 2nd level(12)
    int k = 1;
    // find the sum at level K
    int ans = root->sumAtKthLevel(root, k);
    cout << ans << endl;

    // find the maximum sum of all the levels
    // here max(5,10,12)=12
    cout << root->maximumLevelSum(root) << endl;
    return 0;
}
