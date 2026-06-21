class Solution {
    public int maxProduct(int[] nums) {

        int maxPro=Integer.MIN_VALUE;
        int pro;
        int n=nums.length;
        
        for( int i=0; i<n; i++){
                pro=1;
            for(int j=i; j<n; j++){
                pro *=nums[j];
                maxPro=Math.max(maxPro,pro);
            }
        }
return maxPro;
        
    }
}

//  The Time Complexity is O(N^3)