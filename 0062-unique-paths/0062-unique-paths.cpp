class Solution {
public:
    int uniquePaths(int m, int n) {

        int dp[101][101];
        if( n==1 && m==1)return 1;

        for(int i=0; i<n-1; i++)
        dp[i][m-1]=1;
        for(int j=0; j<m-1; j++)
        dp[n-1][j]=1;
    
    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
        }
    }
    return dp[0][0];
        
    }
};