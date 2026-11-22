class Solution {
public:
    int minimumDeleteSum(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp);
    }
    int solve(string& s1, string& s2, int i, int j,vector<vector<int>>&dp){
        
        if( i>=s1.size() && j>=s2.size())return 0;
         
        if(dp[i][j] != -1)return dp[i][j];

        if(i>=s1.size())
        return dp[i][j]=s2[j]+solve(s1,s2,i,j+1,dp);

        if(j>=s2.size())
        return dp[i][j]=s1[i]+solve(s1,s2,i+1,j,dp);

        
        if( s1[i]==s2[j])
        return dp[i][j]=solve(s1,s2,i+1,j+1,dp);

       else{
            return dp[i][j]=min(s1[i]+solve(s1,s2,i+1,j,dp),s2[j]+solve(s1,s2,i,j+1,dp));
       }

    }
};