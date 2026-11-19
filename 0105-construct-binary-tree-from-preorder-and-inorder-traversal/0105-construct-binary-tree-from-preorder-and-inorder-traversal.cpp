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
    TreeNode* buildTree(vector<int>& pre,int pst,int pend,vector<int>& in,int ist,int iend,map<int,int>& inMap){
        if(ist>iend || pst>pend)return NULL;
        
        TreeNode* root=new TreeNode(pre[pst]);
        int inRoot=inMap[root->val];
        int numLeft=inRoot-ist;

        root->left=buildTree(pre,pst+1,pst+numLeft,in,ist,inRoot-1,inMap);
        root->right=buildTree(pre,pst+numLeft+1,pend,in,inRoot+1,iend,inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.empty() || pre.size() != in.size())return NULL;
        map<int, int>inMap;
        for(int i=0; i<in.size(); i++){
            inMap[in[i]]=i;
        }
        TreeNode* root=buildTree(pre,0,pre.size()-1,in, 0,in.size()-1,inMap);

        return root;
    }
};