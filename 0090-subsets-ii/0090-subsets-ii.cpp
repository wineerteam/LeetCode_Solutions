class Solution {
    vector<vector<int>>ans;
 void solve(vector<int>&arr, vector<int>&curr, int i){
       if( i>=arr.size()){
        ans.push_back(curr);
        return;
       }
       curr.push_back(arr[i]);
       solve(arr,curr,i+1);
       curr.pop_back();

       while( i+1<arr.size() && arr[i] == arr[i+1]){
        i++;
       }
       solve(arr,curr,i+1);
 }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<int>curr;
        sort(arr.begin(),arr.end());
        solve(arr,curr,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};