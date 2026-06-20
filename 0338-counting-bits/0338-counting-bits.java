class Solution {
    public int[] countBits(int n) {

        int ans []=new int [n+1];
        
        for( int i=1; i<ans.length;i++){
                   // built function for the count 1 bit .
                  ans[i]=Integer.bitCount(i);
        }
        return ans;
    }
}