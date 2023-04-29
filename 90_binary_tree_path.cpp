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
};

void paths(TreeNode *root, string ans, vector<string> &ansArray)
{
    if (!root)
        return;
    if (root->left || root->right)
    {
        ans += to_string(root->val);
        ans += "->";
    }
    else
    {
        ans += to_string(root->val);
        ansArray.push_back(ans);
    }
    paths(root->left, ans, ansArray);
    paths(root->right, ans, ansArray);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ansArray;
    string ans = "";
    paths(root, ans, ansArray);
    return ansArray;
}

int main()
{
    TreeNode *r = new TreeNode(4);
    TreeNode *root = r;
    r->left = new TreeNode(6);
    r->right = new TreeNode(1);
    r->left->left = new TreeNode(2);
    r->left->left->right = new TreeNode(10);
    r->right->left = new TreeNode(5);
    vector<string> possiblePaths = binaryTreePaths(root);
    for (int i = 0; i < possiblePaths.size(); i++)
        cout << possiblePaths[i] << "\n";
    cout << endl;

    return 0;
}