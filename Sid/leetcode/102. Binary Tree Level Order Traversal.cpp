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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> nodes;
        vector<vector<int>> ans;

        if (root == nullptr)
        {
            return {};
        }

        nodes.push(root);

        while (!nodes.empty())
        {
            queue<TreeNode *> temp;
            vector<int> level;
            while (!nodes.empty())
            {
                TreeNode *top_node = nodes.front();
                nodes.pop();
                level.push_back(top_node->val);
                if (top_node->left)
                {
                    temp.push(top_node->left);
                }
                if (top_node->right)
                {
                    temp.push(top_node->right);
                }
            }

            ans.push_back(level);
            nodes = temp;
        }

        return ans;
    }
};