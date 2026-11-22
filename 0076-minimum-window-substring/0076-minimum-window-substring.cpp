class Solution {
public:
    string minWindow(string s, string t) {

        int n=s.size();

        if( t.size() > n)return "";

        unordered_map<char,int>mp;
        
        for(char &ch: t)
        mp[ch]++;
        
        int rqc=t.size();

        int i=0,j=0;

        int WS=INT_MAX;
        
        int start_i=0;

     // story starts

        while(j<n){
            char ch=s[j];

            if(mp[ch] > 0) //  frequce greater than zero h
            rqc--;

            mp[ch]--;

            while(rqc ==0){
                // start shrinking the window
                int cws=j-i+1;

                if(WS>cws){  // min window size
                WS=cws;
                start_i=i;
                    }

                    mp[s[i]]++;

                    if(mp[s[i]]>0){
                        rqc++;
                    }
                    i++;
                
            }
            j++;
        }

          return WS == INT_MAX ? "":s.substr(start_i,WS);
    }
};