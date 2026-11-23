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
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        vector<int>sorted=ans;
        sort(sorted.begin(),sorted.end());

        int x=-1;
        int y=-1;
        for(int i=0; i <ans.size(); i++){
            if( ans[i] !=sorted[i]){
                if(x==-1)x=ans[i];
                else y=ans[i];
            }
        }
        replace(root,x,y);
    }
    void inorder(TreeNode* root, vector<int>&ans){
        if(!root)return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

        
    }
    void replace(TreeNode* root, int x, int y){
        if(!root)return ;
        if( root->val==x)root->val=y;
        else if(root->val==y)root->val=x;
        replace(root->left,x,y);
        replace(root->right,x,y);
    }
};