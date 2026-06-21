class Solution {
public:
     int t[1001][1001];
     bool solve(string &s, int i, int j){
           
           // base case 
           if( i>=j) return 1;
           
           if(t[i][j] !=-1) return t[i][j];

           if( s[i]==s[j])
           return  t[i][j]=solve(s,i+1,j-1);
           

           return t[i][j]=0;
     }
    string longestPalindrome(string s) {
        int n = s.length();
       memset(t, -1, sizeof(t));
        int maxl=0;
        int sp = 0;
        for( int i=0; i<n; i++){
            for( int j=i; j<n; j++){
                if( solve(s,i,j)){
                   if(j-i+1>maxl){
                    maxl=j-i+1;
                    sp=i;
                   }
                }
            }
        }
        return s.substr(sp,maxl);
    }
};

// time complexity O(N^3)
//  use dp 


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna