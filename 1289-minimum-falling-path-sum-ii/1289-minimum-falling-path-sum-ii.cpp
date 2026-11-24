class Solution {
    // int N;
    int solve(vector<vector<int>>& arr,int r,int prev,vector<vector<int>>&dp){
        int N=arr.size();
        if( r==N)return 0;
        if(dp[r][prev+1] !=INT_MAX)return dp[r][prev+1];
        int ans=INT_MAX;
        for(int j=0; j<N; j++){

            if(j==prev)continue;
            
            int sum=arr[r][j]+solve(arr,r+1,j,dp);
            ans=min(sum,ans);
        }
        return dp[r][prev+1]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
       vector<vector<int>>dp(n+1,vector<int>(n+2,INT_MAX));
        return solve(arr,0,-1,dp);
        
    }
};