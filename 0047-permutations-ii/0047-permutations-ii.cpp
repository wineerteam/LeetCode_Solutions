class Solution {
    
    vector<vector<int>>ans;
    set<vector<int>>st;
    int n;
    
    void solve(int idx, vector<int> &arr){
        if( idx==n){
           if( st.find(arr)==st.end()){
            st.insert(arr);
            ans.push_back(arr);
            return ;        
               }
        }

               for( int i=idx; i<n; i++){
                swap(arr[i],arr[idx]);
                solve(idx+1, arr);
                swap(arr[i],arr[idx]);
               }
        }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

       n =nums.size();
       solve(0,nums);
       return ans;
        
    }
};