class Solution {

public:
void solve(vector<int>& cnd, int tar,vector<int>&curr,int idx,vector<vector<int>>&ans){
    if(tar<0)return;
    if(tar==0){
        ans.push_back(curr);
        return;
    }
    for(int i=idx; i<cnd.size(); i++){
        if(i>idx && cnd[i] == cnd[i-1]){
            continue;
        }
        curr.push_back(cnd[i]);
        solve(cnd, tar-cnd[i],curr,i+1,ans);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& cnd, int tar) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(cnd.begin(),cnd.end());
        solve(cnd,tar,curr,0,ans);
        return ans;
    }
};