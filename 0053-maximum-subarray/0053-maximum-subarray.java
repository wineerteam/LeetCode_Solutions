class Solution {
    public int maxSubArray(int[] arr) {

        int maxi=Integer.MIN_VALUE;
        int sum=0;
        
        for( int i=0; i<arr.length; i++){
            
             sum +=arr[i];

             if( maxi < sum ) maxi=sum;
             if( sum < 0) sum=0;
        }
        
           
        return maxi;
    }
}

        // 1. brute forces  Tc--o(n^3)
        // 2. we can better solution Tc--o(n^2)
        // 3. we can optimize this problem  Tc--o(n)
        // 4. Let me Explain it... 