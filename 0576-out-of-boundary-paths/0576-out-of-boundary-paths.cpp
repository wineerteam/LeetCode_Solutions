class Solution {

    int m,n;
     const int mod=1e9+7;
     int dp[55][55][55];

     int solve(int sr,int sc, int mm){
        if( sr>=m || sr<0 || sc>=n || sc<0 )return 1;

        if(  mm<=0)return 0;  // move khatam ho gya h

        if( dp[sr][sc][mm] != -1)return dp[sr][sc][mm] ;

        // move 4direction
       
        
          int lft=solve(sr,sc-1,mm-1) % mod;
          int rgt=solve(sr,sc+1,mm-1) % mod;
          int top=solve(sr-1,sc,mm-1) % mod;
          int dwn=solve(sr+1,sc,mm-1) % mod;
          int ans=(lft+rgt)%mod;
          int ans1=(top+dwn) % mod;

        
          return dp[sr][sc][mm] = (ans+ans1) % mod;
     }

public:
    int findPaths(int M, int N, int mm, int sr, int sc) {
        m=M;
        n=N;
        memset(dp,-1,sizeof(dp));
        return solve(sr,sc,mm);

    }
};