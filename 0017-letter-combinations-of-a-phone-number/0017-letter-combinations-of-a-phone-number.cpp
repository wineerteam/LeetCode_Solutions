class Solution {
    void solve(vector<string>&mp, vector<string>&ans,string&dgt,string &curr,int i){
        if( i==dgt.length()){
            ans.push_back(curr);
            return ;

        }

        // find the digit

        int digit=dgt[i]-'0';
        string latter=mp[digit];
        for(char ch:latter){
            curr.push_back(ch);
            solve(mp,ans,dgt,curr,i+1);
            curr.pop_back();

        }
    }
public:
    vector<string> letterCombinations(string dgt) {


        // find the 
        
        vector<string>ans;
        // base case the 
        if( dgt.length()==0)return ans;


        vector<string>mp={""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


        string curr="";
        solve(mp,ans,dgt,curr,0);
        return ans;

        
    }
};