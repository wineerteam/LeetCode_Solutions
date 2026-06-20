class Solution {
    public int[] countBits(int n) {

        // we can optimized 
     int ans []=new int[n+1];
     if( n == 0) return ans;
     for( int i=1; i<=n; i++){
        // if odd number then divid by 2+1;
        if( i % 2 ==1){
            ans[i]=ans[i/2]+1;
        }
        else{
            ans[i]=ans[i/2];
        }
     }
        return ans;
    }
}