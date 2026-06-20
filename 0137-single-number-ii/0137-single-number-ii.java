class Solution {
    public int singleNumber(int[] nums) {

        int ans  =0;

        /// check  1 to 32 bit one by one 
        for( int i=0; i<=31; i++){

            // find left shit
            int temp = (1 << i);
            int countOne=0;
            for( int num:nums){
                if( (num & temp ) != 0){
                    countOne++;
                }
            }
            
            if( countOne % 3 == 1){
                ans = (ans | temp);
            }
        }
        return ans;
    }
}
// 1. is brute force using hasmap use extra space o(n)
// 2. use sorting alg with point which take extra time 
// 3. use Bitmanipulation which is genralized solution with no extra space used and more optimized solutions 