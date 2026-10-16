class Solution {
    int dp[10001];
    int solve( int n){
        if (n == 0)return 0;

       if( dp[n] != -1) return dp[n];
        int mnans=INT_MAX;
        for(int i=1; i*i<=n; i++){
            int temp=1+solve(n-i*i);
            mnans=min(mnans,temp);
        }
        return dp[n]=mnans;
    }
public:
    int numSquares(int n) {
      memset(dp,-1,sizeof(dp));
        return solve( n);
        
    }
};