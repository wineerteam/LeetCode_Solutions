class Solution {

    int solve(vector<int>&arr, int i,vector<int>&dp){
        int ans=0;
        if(dp[i] !=-1)return dp[i];
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                ans=max(ans,solve(arr,j,dp)+1);
            }
        }
        return dp[i]= ans;
    }
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,solve(arr,i,dp));
        }        
        return ans+1;
    }
};