class Solution {
    int dp[101];
    int ans(vector<int>&arr,int i, int sz){
        if(i>sz)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=arr[i]+ans(arr,i+2,sz);
        int ntake=ans(arr,i+1,sz);
        return dp[i]= max(take,ntake);
    }
public:
    int rob(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
    int n=arr.size();
    
    if(n==1)return arr[0];
    if(n==0)return 0;
    int case2=ans(arr,0,n-2);
     memset(dp,-1,sizeof(dp));
    int case1=ans(arr,1,n-1);

        return max(case2,case1);
    }
};