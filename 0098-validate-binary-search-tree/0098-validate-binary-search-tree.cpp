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
    bool isValidBST(TreeNode* root) {
        // if( !root )return true;
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
    bool solve(TreeNode* root,long long mn,long long mx){
        if( root == NULL   )return true;
        if(root->val<=mn || root->val>=mx)return false;

        bool left=solve(root->left,mn,root->val);
        bool right=solve(root->right,root->val,mx);

        return left && right;
    }
};