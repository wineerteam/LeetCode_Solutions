class Solution {
    public int maxProduct(int[] nums) {

        int ans = Integer.MIN_VALUE;
        int pre=1 , suf=1;
        int n=nums.length;
        for(int i=0; i<n; i++){
            
            // if zoro foun in subarray then reset the value
            // reset kar region h. zero value in subarray complete zero kr dega 
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            // find product left side with rigth side and jo max ho include 
            // left or right side se find krne ka logic h becasue of -ve  in odd times 
            pre *=nums[i];
            suf *=nums[n-1-i];

            // inlcude max it can be prefix side or sufix side 
            ans=Math.max(ans,Math.max(pre,suf));
        }
        return ans;
    }
}

// 1. osbservation based intitution TimeComplexity is O(N)
// 2. brute forces                  TimeCompledity is O(N^2)
// 3. brute forces                  TimeComplexity is O(N^3)