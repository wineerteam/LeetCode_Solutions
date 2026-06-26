class Solution {
    public boolean canJump(int[] nums) {

        int n=nums.length;
        int max =0;
        for( int i=0;i<n;i++){
            
            // aage nhi jane h.
            if(i>max) return false;

            // update maxireachable
            max=Math.max(i+nums[i],max);
        }
        
        return true;
    }
}