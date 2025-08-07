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
    // TreeNode * buildTreeHelper(int start, int end, vector<int>& preorder, vector<int>& inorder){
    //     // if(root == nullptr) return nullptr;

    //     if(start > end) return nullptr;
    //     if(start == end){
    //         TreeNode * newNode = new TreeNode(inorder[start]);
    //         newNode -> left = nullptr;
    //         newNode -> right = nullptr;
    //         return newNode;
    //     }

    //     TreeNode * root = new TreeNode(preorder[start]);
    //     // int n = preorder.size();
    //     int root_coord = 0;
    //     for(int i = start; i <= end; i++){
    //         if(inorder[i] == root -> val){
    //             root_coord = i;
    //             break;
    //         }
    //     }

    //     root -> left = buildTreeHelper(start, root_coord - 1, preorder, inorder);
    //     root -> right = buildTreeHelper(root_coord + 1, end, preorder, inorder);

    //     return root;
    // }

    TreeNode *TreeHelper(int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorderMap, int &preorderIdx)
    {
        if (inStart > inEnd)
            return nullptr;
        if (preorderIdx == preorder.size())
            return nullptr;
        int root_val = preorder[preorderIdx];
        preorderIdx++;
        TreeNode *root = new TreeNode(root_val);

        int inorderIdx = inorderMap[root_val];
        root->left = TreeHelper(inStart, inorderIdx - 1, preorder, inorder, inorderMap, preorderIdx);
        root->right = TreeHelper(inorderIdx + 1, inEnd, preorder, inorder, inorderMap, preorderIdx);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // TreeNode * root = preorder[0];
        int n = preorder.size();
        // int root_coord = 0;
        // for(int i = 0; i < n; i++){
        //     if(inorder[i] == root -> val){
        //         root_coord = i;
        //         break;
        //     }
        // }
        unordered_map<int, int> inorderMap;
        int preorderIdx = 0;
        for (int i = 0; i < n; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        return TreeHelper(0, n - 1, preorder, inorder, inorderMap, preorderIdx);
        // return root;
    }
};