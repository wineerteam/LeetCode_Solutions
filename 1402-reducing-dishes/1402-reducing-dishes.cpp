class Solution {
    int n;
    int dp[501][501];
    int solve(vector<int>&arr, int i, int time){
        if( i==n){
            return 0;
        }
        if(i>n)return INT_MIN;
        if( dp[i][time] != -1)return dp[i][time];

     int   take =arr[i]*time+solve(arr, i+1, time+1);
     int   ntake=solve(arr, i+1,time);
     return dp[i][time]= max(take, ntake);
        
    }
public:
    int maxSatisfaction(vector<int>& arr) {

         n=arr.size();
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,1);// sorted array pass, index , time 

        
    }
};