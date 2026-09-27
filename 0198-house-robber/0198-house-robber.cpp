class Solution {
    int dp[101];
    int ans(vector<int>&arr, int i){
        if(i>=arr.size()) return 0;
       if( dp[i]!=-1)return dp[i];
      int take=arr[i]+ans(arr,i+2);
      int ntake=ans(arr,i+1);
      return dp[i]=max(take,ntake);
    }


    
public:
    int rob(vector<int>& arr) {
      memset(dp,-1,sizeof(dp));
        return ans(arr,0);
    }
};