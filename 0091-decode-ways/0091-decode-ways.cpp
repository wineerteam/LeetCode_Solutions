class Solution {
    int dp[101];
    bool isValid(string s){
        // we two conditions 
        if(s[0]=='0') return false;
        int num=stoi(s);
        return (num>=1 && num<=26);
    }

    int solve(string &s, int i){
            if(i==s.length()) return 1;
            if(i>s.length())return 0;
            if( dp[i] != -1) return dp[i];
            // before the take check string is valid or not
            // Valid Conditions 
            int take=0, ntake=0;
            if( i<=s.length() && isValid(s.substr(i,1)) )
             take=solve(s,i+1);

            //ntake need to valid condtions 
            if( i+1<=s.length() && isValid(s.substr(i,2)) )
             ntake=solve(s,i+2);

            return dp[i]=take+ntake;

    }
public:
    int numDecodings(string s) {
        // string str="";
      memset(dp,-1,sizeof(dp));
        if(s[0]=='0')  return 0;
        return solve(s,0);
                
    }
};