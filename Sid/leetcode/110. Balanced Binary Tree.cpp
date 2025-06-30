/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + max(depth(root->right), depth(root->left));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *topnode = nodes.front();
            nodes.pop();

            int depth_right = 0, depth_left = 0;

            if (topnode->right)
            {
                nodes.push(topnode->right);
                depth_right = depth(topnode->right);
            }
            if (topnode->left)
            {
                nodes.push(topnode->left);
                depth_left = depth(topnode->left);
            }

            if (abs(depth_left - depth_right) > 1)
                return false;
        }

        return true;
    }
};