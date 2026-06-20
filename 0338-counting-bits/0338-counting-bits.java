class Solution {
    public int[] countBits(int n) {

        int ans []=new int [n+1];
        
        for( int i=1; i<ans.length;i++){
                   // built function for the count 1 bit .
                   int count =0;
            for( int j=31; j>=0;j--){
                if(((i>>j)&1)==1)count++;
            }
            ans[i]=count;
        }
        return ans;
    }
}