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
    TreeNode* buildTree(vector<int>& in, vector<int>& ps) {
        if( in.empty() || in.size() != ps.size())return NULL;
        map<int,int>mp;
        for(int i=0; i<in.size(); i++){
            mp[in[i]]=i;
        }

        TreeNode* root=buildTree(in,0,in.size()-1,ps,0,ps.size()-1,mp);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& in,int ist,int ie, vector<int>& ps,int pst,int pe,map<int,int>& mp){
        if( ist>ie || pst>pe)return NULL;

       TreeNode* root=new TreeNode(ps[pe]);
       int inRoot=mp[ps[pe]];
       int nleft=inRoot-ist;


        root->left=buildTree(in,ist,inRoot-1,ps,pst,pst+nleft-1,mp);
        root->right=buildTree(in,inRoot+1,ie,ps,pst+nleft,pe-1,mp);

        return root;
    }
};