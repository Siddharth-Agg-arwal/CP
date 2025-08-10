#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left, *right;
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};

TreeNode *formTree(const string &s, int &i)
{
    if (i >= s.size())
        return nullptr;

    TreeNode *root = new TreeNode(s[i]);
    i++;

    if (i < s.size() && s[i] == '?')
    {
        i++;
        root->left = formTree(s, i);
    }
    else if (i < s.size() && s[i] == ':')
    {
        i++;
        root->right = formTree(s, i);
    }
    return root;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    string s;
    cin >> s;
    int idx = 0;
    TreeNode *root = formTree(s, idx);
    printTree(root);
}
