class Solution {
public:
    int t[201][200*100+1];
    bool solve(vector<int>& arr,int i,int x){
        // base case
        if( x == 0) return true;

        if( i>=arr.size()) return false;
        
        if( t[i][x] != -1) return t[i][x];

        // take  and non_take
        bool take=false;
        if(x >= arr[i])
         take=(i+1<=arr.size())&&solve(arr,i+1,x-arr[i]);

        bool ntake=(i+1<=arr.size())&&solve(arr,i+1,x);

            return t[i][x]=take||ntake;
        
    }
    bool canPartition(vector<int>& nums) {
    memset(t, -1,sizeof(t));
    int sum =0;
    for( int num:nums){
        sum+=num;
    }
    int x =sum/2;
    if( sum%2 !=0)return false;
    
    return solve(nums,0,x);
        
    }
};
