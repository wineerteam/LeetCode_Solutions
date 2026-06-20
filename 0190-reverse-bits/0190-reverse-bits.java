class Solution {
    public int reverseBits(int n) {

        // result declare for the ans
        int result  = 0;
        
        // base case 
        if( n == 0) return result;

        // traverse 1 to 32 bits 
        for( int i=1; i<=32; i++){

            // result shit left by 1 bit 
            result = (result<<1);

            // right bit of n add in result throw or operator 
            result= (result|(n&1) );

            // remove right bit from 1 bit throw right shit by 1 bit 
            n=n>>1;

        }
        return result ;
    }
}