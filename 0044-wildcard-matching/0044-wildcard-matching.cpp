class Solution {
public:
    bool isMatch(string& s, string& p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0,dp);
        
    }
    bool solve(string& s, string& p, int i, int j,vector<vector<int>>&dp){
        if( i==s.size() && j==p.size())return true;
        if( j>=p.size())return false;

        if( dp[i][j] != -1)return dp[i][j];

        if(i==s.size()){
            if(p[j]=='*')
            return dp[i][j]=solve(s,p,i,j+1,dp);

            return false;
        }

        if( s[i]==p[j] || p[j]=='?')
        return dp[i][j]=solve(s,p,i+1,j+1,dp);

       if(p[j]=='*') 
       return dp[i][j]=solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp);    

        return false;
    }
};