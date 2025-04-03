/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            stringstream out;
            serialize(root, out);
    
            return out.str();
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            stringstream in(data);
    
            return deserialize(in);
        }
    
        void serialize(TreeNode* root, stringstream& out) {
            if (root) {
                out << to_string(root->val) << ' ';
                serialize(root->left, out);
                serialize(root->right, out);
            } else {
                out << "# ";
            } 
        }
    
        TreeNode* deserialize(stringstream& in) {
            string s;
            in >> s;
            if (s == "#") {
                return nullptr;
            }
    
            TreeNode* node = new TreeNode(stoi(s));
            node->left = deserialize(in);
            node->right = deserialize(in);
    
            return node;
        }
    };
    
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    // Time: O(n)
    // Space: O(n)