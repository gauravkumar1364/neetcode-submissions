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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder,int instrt,int inend, vector<int>& preorder,int prestrt,int preend,map<int,int>&mp ){
        if(prestrt>preend || instrt>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestrt]);
        int inroot = mp[root->val];
        int numsleft = inroot - instrt;
        root->left = buildTree(inorder , instrt,inroot-1,preorder,prestrt+1,prestrt+numsleft,mp);
        root->right = buildTree(inorder , inroot+1,inend,preorder,prestrt+numsleft+1,preend,mp);
        return root;
    }

};