class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        int n=arr.size();
        unordered_map<long,int>mp[n];
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long diff=(long)arr[i]-arr[j];
                auto it=mp[j].find(diff);

                int cnt_at_j= it==end(mp[j])?0:it->second;
                mp[i][diff] +=cnt_at_j+1;
                ans +=cnt_at_j;
            }
        }

        return ans;
    }
};