class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
       int ans=0;
       if( arr.size()<2)return ans;
      vector<int>dp(arr.size(),0);
       for(int i=2; i<arr.size(); i++){
        if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]){
            dp[i]=dp[i-1]+1;
            ans +=dp[i];
            
        }
       }

       
        return ans;
    }
};