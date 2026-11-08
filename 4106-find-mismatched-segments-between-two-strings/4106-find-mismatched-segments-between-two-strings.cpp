class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        int n=s1.length();
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
                vector<string>temp;
            if( s1[i] == s2[i])continue;
           
            
            else {
                 int st=i;
                 int cnt=0;
                 while( i<n && s1[i] != s2[i]){
                    cnt++;
                    i++;
                 }
                if(cnt>0){
                    temp.push_back(s1.substr(st,cnt));
                    temp.push_back(s2.substr(st,cnt));

                }
                ans.push_back(temp);
                i--;

            }
        }


        

        return ans;
    }
};