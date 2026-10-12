class Solution {
    
    int solve(vector<int>& arr, int target,int i){
        if(i==0)
        return (target==0)?1:0;
        if(i<0)return 0;

        // take
        
        int take=solve(arr,target-arr[i-1],i-1);
        int ntake=solve(arr,target+arr[i-1],i-1);

        return take+ntake;
    }
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        
        return solve(arr,target,n);
    }
};