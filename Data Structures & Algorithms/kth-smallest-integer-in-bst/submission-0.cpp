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
    void inorder(TreeNode* root,int& k,int& n,int& ans){
        if(root==NULL)return;
        inorder(root->left,k,n,ans);
        n++;
        if(k==n){
            ans=root->val;
            return;
        }
        inorder(root->right,k,n,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=1,n=0;
        inorder(root,k,n,ans);
        return ans;
    }
};