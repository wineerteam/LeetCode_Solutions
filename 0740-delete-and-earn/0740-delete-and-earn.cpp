class Solution {

    public:
    int solve(vector<int>&arr,int i,vector<int> &dp){
        if( i>=arr.size()) return 0;
        if( dp[i] != -1)return dp[i];

        int take= arr[i]+solve(arr,i+2,dp);
        int ntake=solve(arr,i+1,dp);
        return dp[i]=max(take,ntake);
    }
public:
    int deleteAndEarn(vector<int>& arr) {
    int mx=*max_element(arr.begin(),arr.end());

    vector<int>a(mx+1);
    for(int x:arr){
        a[x]+=x;
    }
    vector<int>dp(mx+1,-1);
  
    return solve(a,0,dp);
       
    }
};