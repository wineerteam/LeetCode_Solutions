class Solution {
    public int hammingWeight(int n) {

        int count =0;
        for( int i =31; i>=0; i--){

            // bit ko right shit kr ke right me lao and then usko 1 se and nikal kr check kro ki wo 1 ke barabar aaye to count ko badhao 
            if( ((n>>i)&1)==1) count++;
        }
         return count;
    }
}