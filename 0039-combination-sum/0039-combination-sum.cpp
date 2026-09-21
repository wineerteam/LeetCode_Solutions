class Solution {
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&arr,int &tar,vector<int>&temp){
               if( idx>=arr.size()|| tar<0){
                return ;
               }
               if( tar==0){
                ans.push_back(temp);
                return ;
               }
                

               for(int i=idx; i<arr.size(); i++){
                  temp.push_back(arr[i]);
                  tar=tar-arr[i];
                  solve(i,arr,tar,temp);
                  tar=tar+arr[i];
                  temp.pop_back();
               }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int>temp;
        solve(0,arr,tar,temp);
        return ans;
    }
};