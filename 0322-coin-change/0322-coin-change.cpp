class Solution {
    #define ll long long

    ll dp[13][10001];
    int solve(vector<int>&cns, int amt, int i){
        if(amt == 0)return 0;
        if(amt<0 || i >= cns.size())return INT_MAX;

        int take=INT_MAX;
        
        if(dp[i][amt] !=-1)return dp[i][amt];

        if( cns[i]<=amt){
    
        int res=solve(cns,amt-cns[i],i);
        
        if( res!=INT_MAX)
          take=1+res;
          }
        

        int ntake=solve(cns,amt,i+1);
        return dp[i][amt]=min(take,ntake);
    }
public:
    int coinChange(vector<int>& cns, int amt) {
         
        memset(dp,-1,sizeof(dp));

        int ans=solve(cns,amt,0);
        
        return (ans !=INT_MAX)?ans:-1;
        }
};