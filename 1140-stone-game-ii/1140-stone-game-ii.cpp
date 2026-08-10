class Solution {
public:
    int f(vector<int>& p,int i,int m,vector<vector<int>>& dp){
        if(i>=p.size()) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int sum=0,ans=0,total=0;
        for(int x=1;x<=2*m && i+x<=p.size();x++){
            sum+=p[i+x-1];
total=accumulate(p.begin()+i,p.end(),0);
            ans=max(ans,sum+total-sum-f(p,i+x,max(m,x),dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& p){
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(p,0,1,dp);
    }
};