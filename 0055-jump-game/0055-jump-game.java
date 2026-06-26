class Solution {
    public boolean canJump(int[] nums) {

        int n = nums.length;
        // use to hme i-1 tak pahucha skta h ya nhi ye store karega 
        boolean ans[]=new boolean[n];
        // store all false wase by default bhi to whi hota h.

        Arrays.fill(ans,false);
        
        // accroding to questions we reach 1st posstion so intialize 
        ans[0]=true;
        
        for( int i=1; i<n; i++){
            // check i-1 to zero tk
            for(int j=i-1; j>=0; j--){
                // check it i-1 tk khud pahuch skta h. or hme i tk pahucha skta both condition try kro
                if( ans[j]==true && j+nums[j] >= i) {
                    ans[i]=true;
                    break;
                }
            }
        }
        return ans[n-1];
    }
}