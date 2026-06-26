class Solution {
    boolean ans(int [] arr,int ind,int n,Boolean []dp){
        
        
        // base case jab wo last index pr hit kr jaye return true; 
        if( ind == n-1) return true;
        if(dp[ind] != null) return dp[ind];
        // jitne value o us ind pr utne movement ko check kro koi true ho return kr do
        for( int i=1; i<=arr[ind]; i++){
            // check to arr[ind] value inde ko aage kr ke 
            if( ans(arr,ind+i,n,dp))
            return dp[ind]=true;
        
        }
        return dp[ind]=false;
    }
    public boolean canJump(int[] nums) {
        int n=nums.length;
        // use memoization becasue tle de rha h. or ke hi ind vairi kr raha so give me one d array
        Boolean [] dp=new Boolean[n+1];
        // Arrays.fill(dp,-1);
        
        return ans(nums,0,n,dp);
        
    }
}

// 1. brute force try to recrusion time complexity is exponential time complexity 
// 2. dp to minimiz because to the time  overlaping problems