class Solution {
    public int maxIceCream(int[] arr, int coins) {
        Arrays.sort(arr);
        int count=0;
        int sum =0;
        if(arr[0]>coins) return 0;
        for( int i=0; i<arr.length; i++){
            if(arr[i]<coins && sum+arr[i]<=coins){
                count++;
                sum+=arr[i];
            }
            if(sum >=coins) break;
            
        }

        return count;
    }
}