class Solution {
    vector<string>ans;
    int n;

    bool isValid(string str){
        if(  str[0]=='0') return false;
        int num=stoi(str);
        if(num>255) return false;
        return true;
    }

    void solve(string &s, int idx, string temp, int parts){
        
        
        if( idx==s.length() && parts==4) {
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }

        // solve teke one int
        if(idx+1<=n)
        solve(s,idx+1,temp+s.substr(idx,1)+".",parts+1);
        
        // solve take two digit
         if(idx+2<=n && isValid(s.substr(idx,2)) )
         solve(s,idx+2,temp+s.substr(idx,2)+".",parts+1);

        // solve take three digit
        if(idx+3<=n && isValid(s.substr(idx,3)) )
         solve(s,idx+3,temp+s.substr(idx,3)+".",parts+1);

    }

public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
         n=s.length();
        // if( n>12) return ans ;
        string temp="";
        int parts=0;
        solve(s,0,temp,parts);
        return ans;

        
    }
};