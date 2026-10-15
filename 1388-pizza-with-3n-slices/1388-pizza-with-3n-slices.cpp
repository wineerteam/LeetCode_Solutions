class Solution {
    int dp[501][501];
    int solve(vector<int>& arr, int i,int lastIndex,int k){
        if( k==0 || i>lastIndex)return 0;
        if(dp[i][k] != -1)return dp[i][k];
        int take=arr[i]+solve(arr,i+2,lastIndex,k-1);
       int ntake=solve(arr,i+1,lastIndex,k);
       return dp[i][k]=max(take,ntake);
    }
public:
    int maxSizeSlices(vector<int>& arr) {
        
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int cost1= solve(arr,0,n-2,n/3);
         memset(dp,-1,sizeof(dp));
        int cost2=solve(arr,1,n-1,n/3);
        return max(cost1,cost2);

    }
};