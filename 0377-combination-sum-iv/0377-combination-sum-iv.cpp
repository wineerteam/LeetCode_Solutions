class Solution {
int ans;
int dp[1001];
    int solve(vector<int>& arr, int target){
        if( target==0)return 1;
        if( target<0)return 0;

        if( dp[target] != -1) return dp[target];
         int ans=0;
        for(int j=0; j<arr.size(); j++){
            ans+=solve(arr,target-arr[j]);
        }
        return dp[target]=ans;
    }
    
public:
    int combinationSum4(vector<int>& arr, int target) {
        memset(dp,-1,sizeof(dp));
    return   solve(arr,target);
    
    }
};