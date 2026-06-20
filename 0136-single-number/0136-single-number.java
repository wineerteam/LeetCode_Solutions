class Solution {
    public int singleNumber(int[] nums) {
        
             int unique = 0;

             // check 1 to 32 bit
             for( int i=0; i<32; i++){
                
                // find left shit of one for each i
                int temp = ( 1 << i);
                int countOne=0;
                for(int num:nums){
                    if( (num & temp) != 0){
                        countOne++;
                    }
                }
                    // each number 2 times 
                if( countOne % 2 == 1){
                   unique = (unique | temp);
                }
             }
             
             return unique ;
    }
}

// 1. solution is brute force is use Hash map
// 2. use pointer with sorting algo 
// 3. use generallize solution with more optimzed Bit Manipulations no extra with tc o(n);