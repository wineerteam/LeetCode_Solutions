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
    int helper(TreeNode* root, int & maxi){
        if( !root )return 0;
         int ls=max(0,helper(root->left,maxi));
        int rs=max(0,helper(root->right,maxi));

       
        maxi=max(maxi,ls+rs+root->val);
        return root->val+max(ls,rs);
    }
public:
    int maxPathSum(TreeNode* root) {

        if(!root)return 0;
        int maxi=INT_MIN;
        helper(root,maxi);
    return maxi;

        
    }
};