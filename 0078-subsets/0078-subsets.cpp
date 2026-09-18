class Solution {
public:
void solve(vector<int>& arr, vector<vector<int>>&ans,vector<int>curr,int i ){
    
    // base condition 
    if( i==arr.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(arr[i]);
    // take 
    solve(arr,ans,curr,i+1);
  

   curr.pop_back();
    //  non-take
    solve(arr,ans,curr,i+1);

}
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(arr,ans,curr,0);
        return ans;
    }
};