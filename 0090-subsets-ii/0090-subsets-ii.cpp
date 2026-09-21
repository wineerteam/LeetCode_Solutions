class Solution {
    vector<vector<int>>ans;
    set<vector<int>>st;
    
    void solve(vector<int>&arr,int i, vector<int>&temp){
        if( i>=arr.size()){
            if( st.find(temp)==st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
                return ;
        }
           
           temp.push_back(arr[i]);
           solve(arr,i+1,temp);
           temp.pop_back();
           solve(arr,i+1,temp);
     

    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>temp;
        solve(arr,0,temp);
       
        return ans;
        
    }
};