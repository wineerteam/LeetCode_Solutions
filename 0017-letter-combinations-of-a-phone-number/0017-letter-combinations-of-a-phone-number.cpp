class Solution {
// Global Variable mention kiya h taki pass n krna pare okey 
  vector<string>ans;
  vector<string> arr;

// method 
  void solve(int idx,string &s , string &temp){
    if( idx==s.length()){
        ans.push_back(temp);
        return ;
    }

    int  dgt=s[idx]-'0';
    string str=arr[dgt];

    for(int i=0; i<str.length(); i++){
        temp.push_back(str[i]);
        solve(idx+1,s,temp);
        temp.pop_back();
    }

  }
public:
    vector<string> letterCombinations(string s) {

       string temp="";
       arr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

       solve(0,s,temp);

       return ans;
        
    }
};

// time complexity is O(4^N*N) 