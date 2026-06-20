class Solution {
    public int hammingWeight(int n) {

        int count = 0;

        while( n > 0){
            // patter dekho jitna 1 bit hoga utna hi bar chale ga ye loop 
            n=n&(n-1);
            count++;
        }
        return count;
    }

}
// 1. check all 32 bit one by one then tc___ O(32)
// 2....Time complexity___ 0(no of 1 bit )
// 3. remainder find kr ke Tc____O(log(N))
// 4.Build in function used in ..Integer.bitCount(n);

