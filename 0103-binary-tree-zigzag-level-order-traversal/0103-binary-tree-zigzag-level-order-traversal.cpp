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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root == NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int sgn=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0; i <sz; i++){
            TreeNode* node=q.front();
            q.pop();

            if(node->left !=NULL)q.push(node->left);
            if(node->right !=NULL)q.push(node->right);
            
                temp.push_back(node->val);
            }
            if(sgn==1){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else{
                ans.push_back(temp);
            }
            sgn=(sgn==1)? 0:1;
            
        }
        return ans;
    }
};