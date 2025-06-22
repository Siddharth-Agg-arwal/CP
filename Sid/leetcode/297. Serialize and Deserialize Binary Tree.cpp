/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> nodes;

        if (root == nullptr)
        {
            return "*";
        }
        nodes.push(root);

        string serialized = "";
        serialized += to_string(root->val);
        int itr = 0;
        while (!nodes.empty())
        {
            TreeNode *top_node = nodes.front();
            nodes.pop();
            if (!top_node->left)
                serialized += ",*";
            if (top_node->left)
            {
                serialized += ',';
                serialized += to_string(top_node->left->val);
                nodes.push(top_node->left);
            }
            if (!top_node->right)
                serialized += ",*";
            if (top_node->right)
            {
                serialized += ',';
                serialized += to_string(top_node->right->val);
                nodes.push(top_node->right);
            }
        }

        // cout << serialized << '\n';
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        if (data[0] == '*')
        {
            return nullptr;
        }

        vector<string> tokens;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
            // cout << token << " ";
        }

        TreeNode *root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode *> nodes;
        nodes.push(root);

        int i = 1;
        while (i < tokens.size() && !nodes.empty())
        {
            TreeNode *parent_node = nodes.front();
            nodes.pop();

            if (tokens[i] != "*")
            {
                TreeNode *left_child = new TreeNode(stoi(tokens[i]));
                parent_node->left = left_child;
                nodes.push(left_child);
            }
            i += 1;

            if (i < tokens.size() && tokens[i] != "*")
            {
                TreeNode *right_child = new TreeNode(stoi(tokens[i]));
                parent_node->right = right_child;
                nodes.push(right_child);
            }
            i += 1;
        }

        // TreeNode * root = nullptr;

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));