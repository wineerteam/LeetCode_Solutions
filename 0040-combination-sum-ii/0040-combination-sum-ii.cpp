class Solution {

public:
void solve(vector<int>& cnd, int tar,vector<int>&curr,int idx,vector<vector<int>>&ans){
    if(tar==0){
        ans.push_back(curr);
        return;
    }
    
    if(tar<0 || idx>=cnd.size())return;
       curr.push_back(cnd[idx]);
       tar=tar-cnd[idx];
       solve(cnd,tar,curr,idx+1,ans);
       tar=tar+cnd[idx];
       curr.pop_back();
       while(idx+1<cnd.size() && cnd[idx]==cnd[idx+1]){
        idx++;
       }
       solve(cnd,tar,curr,idx+1,ans);
}
    vector<vector<int>> combinationSum2(vector<int>& cnd, int tar) {
        sort(cnd.begin(),cnd.end());
        vector<vector<int>>ans;
        vector<int>curr;
      
        solve(cnd,tar,curr,0,ans);
        return ans;
    }
};