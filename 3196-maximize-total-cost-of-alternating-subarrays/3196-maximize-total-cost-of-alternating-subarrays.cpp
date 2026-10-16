
class Solution {
#define ll long long 
ll dp[100001][2];
    ll solve(int i,int sgn, vector<int>& arr){
        if( i==arr.size())
        return 0;

        ll p1=-1e18;
        ll p2=-1e18;

        if(dp[i][sgn] != -1)return dp[i][sgn];

        if( sgn==0){
            p1=arr[i]+solve(i+1,1,arr);
        }
        else{
            p1=-arr[i]+solve(i+1,0,arr);
        }

        p2=arr[i]+solve(i+1,1,arr);

        return dp[i][sgn] = max(p1,p2);
    }
public:
    long long maximumTotalCost(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,arr);
    }
};