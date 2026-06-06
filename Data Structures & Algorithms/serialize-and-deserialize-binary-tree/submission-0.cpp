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

    // ---------- SERIALIZE HELPER ----------
    void solve(TreeNode* root, string &s){

        if(root == NULL){
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        solve(root->left, s);
        solve(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";

        solve(root, s);

        return s;
    }

    // ---------- DESERIALIZE HELPER ----------
    TreeNode* buildTree(stringstream &ss){

        string str;

        getline(ss, str, ',');

        if(str == "N") return NULL;

        TreeNode* root = new TreeNode(stoi(str));

        root->left = buildTree(ss);
        root->right = buildTree(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);

        return buildTree(ss);
    }
};