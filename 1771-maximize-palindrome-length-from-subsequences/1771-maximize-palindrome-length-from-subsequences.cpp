class Solution {
    int solve(string& s,int i, int j,int x,int& ans,vector<vector<int>>&dp){
        if(i>j )return 0;
        if(i==j)return 1;
        int ln=0;

         if(dp[i][j] !=-1)return dp[i][j];

        if(s[i]==s[j]){
            ln=max(ln,2+solve(s,i+1,j-1,x,ans,dp));
           if( i<x && x<=j)
           ans=max(ln, ans);
        }
       else 
        ln=max(ln,max(solve(s,i+1,j,x,ans,dp),solve(s,i,j-1,x,ans,dp)));
        
        return dp[i][j]= ln;
    }
public:
    int longestPalindrome(string& s, string& ss) {
        string sss=s+ss;
        int n=sss.size();
        int x=s.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         solve(sss,0,n-1,x,ans,dp);
        return ans;
        
    }
};