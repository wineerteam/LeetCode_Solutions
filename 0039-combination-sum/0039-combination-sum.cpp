class Solution {
    vector<vector<int>>ans;
    void solve(int idx, vector<int>&arr, int tar, vector<int>&temp){
        if(idx>=arr.size() || tar<0)return;
        if(tar==0){
            ans.push_back(temp);
            return;
        }
           
                temp.push_back(arr[idx]);
                tar=tar-arr[idx];
                solve(idx,arr,tar,temp);
                tar=tar+arr[idx];
                temp.pop_back();
                solve(idx+1,arr,tar,temp);  //exclude move next
            
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        
        vector<int>temp;
        solve(0,arr,tar,temp);
        return ans;
    }
};