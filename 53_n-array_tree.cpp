#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }

    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (st.size())
        {
            Node *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            vector<Node *> vec = temp->children;
            for (int i = vec.size() - 1; i >= 0; i--)
                st.push(vec[i]);
        }
        return ans;
    }

    vector<int> postorder(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;
        stack<Node *> st;
        st.push(root);
        while (st.size())
        {
            Node *temp = st.top();
            st.pop();
            for (int i = 0; i < temp->children.size(); i++)
                st.push(temp->children[i]);
            ans.push_back(temp->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size();
            // q.pop();
            vector<int> v;
            while (n)
            {
                Node *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                vector<Node *> child = temp->children;
                for (int i = 0; i < child.size(); i++)
                    q.push(child[i]);
                n--;
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main()
{
    Node *r = new Node(1);
    Node *root = r;
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);
    Node *node5 = new Node(6);
    Node *node6 = new Node(7);

    node1->children.push_back(node4);
    node1->children.push_back(node5);
    node1->children.push_back(node6);
    r->children.push_back(node1);
    r->children.push_back(node2);
    r->children.push_back(node3);
    vector<int> preOrder = root->preorder(root);
    vector<int> postOrder = root->postorder(root);
    vector<vector<int>> leverOrder = root->levelOrder(root);
    cout << "Pre order:";
    for (int i = 0; i < preOrder.size(); i++)
        cout << preOrder[i] << " ";
    cout << endl;
    cout << "Post order:";
    for (int i = 0; i < postOrder.size(); i++)
        cout << postOrder[i] << " ";
    cout << endl;
    cout << "Level Order:\n";
    for (int i = 0; i < leverOrder.size(); i++)
    {
        for (int j = 0; j < leverOrder[i].size(); j++)
            cout << leverOrder[i][j] << " ";
        cout << endl;
    }
    return 0;
}