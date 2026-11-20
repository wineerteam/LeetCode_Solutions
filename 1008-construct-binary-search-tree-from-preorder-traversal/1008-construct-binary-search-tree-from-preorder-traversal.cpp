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
    TreeNode* bstFromPreorder(vector<int>& a) {
        int i=0;
        return helper(a,i,INT_MAX);
    }
    TreeNode* helper(vector<int>&a, int& i, int mx){
        
         if( i==a.size() || a[i]>mx)return NULL;
        
        TreeNode* root=new TreeNode(a[i++]);
        root->left=helper(a,i,root->val);
        root->right=helper(a,i,mx);
        return root;
    }
};