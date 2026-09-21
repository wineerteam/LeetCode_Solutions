class Solution {
    vector<vector<int>>ans;
    void solve(vector<int>&arr, int i, vector<int>&temp){
               
               // base case 
                if(i>=arr.size()){
                    ans.push_back(temp);
                    return;

                }

                // take 
                temp.push_back(arr[i]);
                solve(arr,i+1,temp);
                temp.pop_back();
                solve(arr,i+1,temp);
                

    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>temp;
        solve(arr,0,temp)
        return ans;
        
    }
};