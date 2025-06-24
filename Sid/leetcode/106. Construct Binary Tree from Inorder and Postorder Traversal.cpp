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
    TreeNode *buildTreeHelper(int inorder_start, int inorder_end, int postorder_start, int postorder_end, vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder_start > inorder_end)
        {
            return nullptr;
        }

        int root_val = postorder[postorder_end];
        // root_node -> val = root_val;
        int split_idx = 0;
        for (int i = inorder_start; i <= inorder_end; i++)
        {
            if (inorder[i] == root_val)
            {
                split_idx = i;
                break;
            }
        }

        int left_size = split_idx - inorder_start;
        // int n = postorder.size();
        TreeNode *root_node = new TreeNode(root_val);
        root_node->left = buildTreeHelper(inorder_start, split_idx - 1, postorder_start, postorder_start + left_size - 1, inorder, postorder);
        root_node->right = buildTreeHelper(split_idx + 1, inorder_end, postorder_start + left_size, postorder_end - 1, inorder, postorder);

        return root_node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // TreeNode * root = new TreeNode(postorder[postorder.size() - 1]);
        int n = postorder.size();
        TreeNode *root = buildTreeHelper(0, n - 1, 0, n - 1, inorder, postorder);
        // root -> right = buildTreeHelper(split_idx + 1, n-1, split_idx, n -2, inorder, postorder);
        return root;
    }
};