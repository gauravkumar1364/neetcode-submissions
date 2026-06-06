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
    int mp(TreeNode* root,int& maxi){
        if(!root){
            return 0;
        }
        int leftsum = max(0,mp(root->left,maxi));
        int rightsum = max(0,mp(root->right,maxi));
        maxi = max(maxi,leftsum+rightsum+root->val);
        return max(leftsum,rightsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        mp(root,maxi);
        return maxi;
    }
};