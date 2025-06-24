/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val > q->val)
        {
            TreeNode *temp = p;
            p = q;
            q = temp;
        }
        // cout << p -> val << " " << q -> val << endl;
        while (root)
        {
            if (q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};