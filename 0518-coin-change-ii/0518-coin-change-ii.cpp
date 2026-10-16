class Solution {
    int dp[301][5001];
    int solve(int amt, vector<int>& cns, int i){
        if( amt==0)return 1;
        if( amt<0 || i>=cns.size())return 0;
        
        if(dp[i][amt] != -1)return dp[i][amt];


        int take=0;
        if( cns[i]<=amt && i<=cns.size())
        take=solve(amt-cns[i],cns,i);

        int ntake=solve(amt,cns,i+1);

        return dp[i][amt]= take+ntake;
    }
public:
    int change(int amt, vector<int>& cns) {
        memset(dp,-1,sizeof(dp));
        return solve(amt,cns,0);
        
    }
};