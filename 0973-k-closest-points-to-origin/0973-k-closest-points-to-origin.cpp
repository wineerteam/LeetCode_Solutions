



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& num, int k) {
        vector<pair<long long,int>>arr;

        for(int i=0; i<num.size(); i++){
            int x=num[i][0];
            int y=num[i][1];
            long long  dist=1LL*x*x+1LL*y*y;
            arr.push_back({dist,i});
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0; i<k; i++){
          int ind= arr[i].second;
          ans.push_back({num[ind][0],num[ind][1]});

        }
        return ans;
    }
};