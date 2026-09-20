class Solution {
public:
vector<vector<int>>ans;
set<int>st;
void solve(vector<int> &arr,vector<int> &temp){
    if( temp.size()==arr.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if( st.find(arr[i])==st.end()){
            temp.push_back(arr[i]);
            st.insert(arr[i]);
            solve(arr,temp);
            temp.pop_back();
            st.erase(arr[i]);
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
          solve(nums,temp);
          return ans;
    }
};