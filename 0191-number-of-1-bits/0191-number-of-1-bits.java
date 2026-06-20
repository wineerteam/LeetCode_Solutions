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

// Time complexity 0(no of 1 bit )