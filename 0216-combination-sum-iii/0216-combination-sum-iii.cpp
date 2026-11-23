class Solution {
    

public:
void solve(vector<int>& cnd, int tar,vector<int>&curr,int idx,vector<vector<int>>&ans,int cnt,int k){
    if(tar==0 && cnt==k){
        ans.push_back(curr);
        return;
    }
    
    
    if(tar<0 || idx>=cnd.size())return;
       curr.push_back(cnd[idx]);
       tar=tar-cnd[idx];
       solve(cnd,tar,curr,idx+1,ans,cnt+1,k);
       tar=tar+cnd[idx];
       curr.pop_back();
       while(idx+1<cnd.size() && cnd[idx]==cnd[idx+1]){
        idx++;
       }
       solve(cnd,tar,curr,idx+1,ans,cnt,k);
}
    vector<vector<int>> combinationSum3(int k, int tar) {
   
        vector<vector<int>>ans;
        vector<int>curr;
        int cnt=0;
      vector<int>cnd={1,2,3,4,5,6,7,8,9};
        solve(cnd,tar,curr,0,ans,cnt,k);
        return ans;
        
    }
};