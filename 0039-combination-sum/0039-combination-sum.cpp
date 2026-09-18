class Solution {
    public:
    void solve(vector<int>&arr,int tar,vector<vector<int>>&ans,vector<int>&curr,int i){
         if( i>=arr.size() || tar<0) return ;
         if(tar == 0){
            ans.push_back(curr);
            return;
         }
        curr.push_back(arr[i]);
        solve(arr,tar-arr[i],ans,curr,i);
        // non take
        curr.pop_back();
        solve(arr,tar,ans,curr,i+1);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& cnd, int tar) {

        vector<vector<int>>ans;
        vector<int>curr;
        solve(cnd,tar,ans,curr,0);
        return ans;

        
    }
};