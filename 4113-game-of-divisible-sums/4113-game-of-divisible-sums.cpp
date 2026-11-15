class Solution {
    #define ll long long 
    ll dp[100001];
    int vs[100001];

    ll solve(vector<int>&arr, int i){
       if( i>=arr.size())return 0;
       if(vs[i]) return dp[i];
       vs[i]=1;
       ll sum=arr[i];
       ll take1=LLONG_MIN;
       
       if( sum % 3==0)
        take1=sum-solve(arr,i+1);
        else
        take1=sum+solve(arr,i+1);

    ll take2=LLONG_MIN;
    if(i+1<arr.size()){
        sum +=arr[i+1];
        if(sum % 3 == 0)
        take2=sum-solve(arr,i+2);
        else
        take2=sum+solve(arr,i+2);
    }

        return dp[i]=max(take1,take2);
    }
    
public:
    long long maxDifference(vector<int>& arr) {
        memset(vs,0,sizeof(vs));
        return solve(arr,0);
    }
};