class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        vector<int>ans;
        int i=0; 
        int j=1;
        while(ans.size()<k){
            if( i<arr.size()&& arr[i]==j){
                i++;
                j++;
                }
            else{
                ans.push_back(j);
                j++;
            }
            
        }
        return ans[k-1];
    }
};