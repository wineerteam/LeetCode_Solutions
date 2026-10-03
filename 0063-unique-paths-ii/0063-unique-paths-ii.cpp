class Solution {
    int n=0,m=0;
    int dp[101][101];
    int solve(vector<vector<int>>& arr,int i, int j){
        if( i==n-1 && j==m-1 && arr[i][j] !=1)return 1;

        if( i>=n || j>=m || i<0 || j<0 || arr[i][j]==1  )
        return 0;

        int take=0,ntake=0;
         if(dp[i][j]!=-1)return dp[i][j];
       
        take=solve(arr,i,j+1);

        ntake=solve(arr,i+1,j);

       return dp[i][j]=take+ntake;
    }
public:

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
         n=arr.size();
         m=arr[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,0);
        
    }
};