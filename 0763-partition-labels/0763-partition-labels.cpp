class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        // for the ans store
        vector<int>ans;
        
        // for the lastindex of occurange
        vector<int>mp(26,-1);

        for( int i=0; i<n; i++){
            int idx = s[i]-'a';
            mp[idx]=i;
        }

        int i=0;
        while( i<n){
            int end = mp[s[i]-'a'];
            int j=i;
            while( j<end){
                end=max(end,mp[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i=j+1;
        }
        return ans;
    }
};

// There is Time Complexity is o(N) ans Space Complexity is O(1);