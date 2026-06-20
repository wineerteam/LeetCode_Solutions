class Solution {
    public int missingNumber(int[] nums) {
        
        // length of nums
        int n=nums.length;

        // find 0 to n sum math formula
        int total_sum = n*(n+1)/2;

        // cal_sum
        int cal_sum=0;
        
        for( int num:nums){
            cal_sum+=num;
        }

        return total_sum-cal_sum;
    }
}