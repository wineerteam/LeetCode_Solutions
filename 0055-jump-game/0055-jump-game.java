class Solution {
    public boolean canJump(int[] nums) {

        // one vairbale use so one d aray sufficent 
        
        boolean arr[]=new boolean [nums.length];
         arr[0]=true;
        for( int i=1; i<nums.length;i++){
            for( int k=i-1; k>=0; k--){
                if(arr[k]==true && k+nums[k] >=i){
                    arr[i]=true;
                    break;
                }
            }
        }
        return arr[nums.length-1];
    }
}