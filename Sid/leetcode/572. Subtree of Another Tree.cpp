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
    bool isSubtreeHelper(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }

        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }

        // cout << root -> val << " " << subRoot -> val << endl;
        if (root->val != subRoot->val)
        {
            return false;
        }

        bool equal = isSubtreeHelper(root->right, subRoot->right) && isSubtreeHelper(root->left, subRoot->left);

        return equal;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        // bool ans = false;

        if (root == nullptr && subRoot == nullptr)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }

        bool ans = false;
        queue<TreeNode *> mainTree;
        mainTree.push(root);

        while (!mainTree.empty())
        {
            TreeNode *top_node = mainTree.front();
            mainTree.pop();

            if (top_node->val == subRoot->val)
            {
                TreeNode *tempSubRoot = subRoot;
                ans = isSubtreeHelper(top_node, tempSubRoot);
                if (ans)
                    return true;
            }

            if (top_node->left)
                mainTree.push(top_node->left);
            if (top_node->right)
                mainTree.push(top_node->right);
        }

        return ans;
    }
};