class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];

           ans+=(i+1)*('z'-ch+1);
        }
        return ans;
    }
};