class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {

        int n=arr.size();
        int m=arr[0].size();
       
       int dp[201][201];
       memset(dp,0,sizeof(dp));
       // row same as it is 
        dp[n-1][m-1]=arr[n-1][m-1];

       // colom same as it is 
       for(int i=n-1; i>=0; i--){
        dp[i][m-1]=arr[i][m-1]+dp[i+1][m-1];
       }
       for(int j=m-1; j>=0; j--){
        dp[n-1][j]=arr[n-1][j]+dp[n-1][j+1];
       }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                dp[i][j]=arr[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};