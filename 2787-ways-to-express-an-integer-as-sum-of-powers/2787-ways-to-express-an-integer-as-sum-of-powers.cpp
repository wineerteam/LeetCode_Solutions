
    #define ll long long
    const int M = 1e9 + 7;
    int dp[301][301];
class Solution {

    int solve(int n, int x, int i, int sum) {
     
    if(sum==n)return 1;
    if(sum>n)return 0;

    if(dp[i][sum] != -1)return dp[i][sum];

    ll p = 1;
    
    /// break conditions  nhi to chalta hi rhega so give me breaking conditon fr the ntake ke liye

    for (int j = 0; j < x; j++) {
        p *= (i + 1);
        if (p > n) break;
    }
    if(p>n)return 0;

    // take 
    int take=solve(n,x,i+1,sum + p);
    // ntake
    int ntake=solve(n,x,i+1,sum);

    return  dp[i][sum]= (take+1LL*ntake)%M;
}

public:
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n,x,0,0)%M;
        
    }
};
