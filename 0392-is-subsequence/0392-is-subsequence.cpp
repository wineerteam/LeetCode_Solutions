class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty())  return false;
        return solve(s,t,0,0);
    }
    bool solve(string s, string t,int i, int j){
        if( j>=t.size() && i>=s.size())return true;
        if(  j>=t.size() )return false;
        
        if( s[i] == t[j]){
           return solve(s,t,i+1,j+1);
        }
              
                return solve(s,t,i,j+1);


    }
};