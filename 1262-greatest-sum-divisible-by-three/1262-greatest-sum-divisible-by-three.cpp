class Solution {
public:
    int maxSumDivThree(vector<int>& arr) {

        int n =arr.size();
        vector<vector<int>>dp(arr.size()+1,vector<int>(3,INT_MIN));
        for(int i=0; i<dp.size();i++ ){
                dp[i][0]=0;
        }

        for(int i=1; i<=n; i++){
        for(int j=0; j<dp[0].size(); j++)
        {
            int ntake=dp[i-1][j];
           int rem = (j - arr[i - 1] % 3 + 3) % 3;

                int take = INT_MIN;

                if(dp[i - 1][rem] != INT_MIN) {
                    take = arr[i - 1] + dp[i - 1][rem];
                }

        
            dp[i][j]=max(take,ntake);
            }
        }


        return dp[n][0];
        
    }
};