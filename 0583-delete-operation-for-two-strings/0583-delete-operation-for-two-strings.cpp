class Solution {
    
public:
    int minDistance(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int match=solve(s1,s2,0,0,dp);
        return n+m-2*match;
    }
    int solve(string s1,string s2, int i, int j,vector<vector<int>>&dp){
        if( i>=s1.size()|| j>=s2.size())
        return 0;
        if(dp[i][j] !=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+solve(s1,s2,i+1,j+1,dp);
        }
        return dp[i][j]=max(solve(s1,s2,i,j+1,dp),solve(s1,s2,i+1,j,dp));
    }
};