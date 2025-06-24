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
    bool validBSTHelper(TreeNode *root_node, long min_val, long max_val)
    {
        if (root_node == nullptr)
        {
            return true;
        }

        if (root_node->val <= min_val || root_node->val >= max_val)
        {
            return false;
        }

        if (root_node->right)
        {
            if (root_node->right->val <= min_val || root_node->right->val <= root_node->val)
            {
                return false;
            }
        }

        if (root_node->left)
        {
            if (root_node->left->val >= max_val || root_node->left->val >= root_node->val)
            {
                return false;
            }
        }

        bool ans = validBSTHelper(root_node->right, root_node->val, max_val) && validBSTHelper(root_node->left, min_val, root_node->val);

        return ans;
    }

    bool isValidBST(TreeNode *root)
    {
        long min_val = LONG_MIN, max_val = LONG_MAX;
        return validBSTHelper(root, min_val, max_val);
    }
};