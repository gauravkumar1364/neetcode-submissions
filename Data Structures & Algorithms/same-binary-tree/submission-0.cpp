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
    void preorder(TreeNode* root,vector<int> &ans){
        
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> q1;
        if(p==NULL&&q==NULL){
            return true;
        }
        if( p== NULL || q==NULL){
            return false;
        }
        return ((p->val == q->val)
            && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right));
        

    }
};