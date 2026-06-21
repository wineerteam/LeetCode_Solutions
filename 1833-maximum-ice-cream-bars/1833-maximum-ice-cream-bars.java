class Solution {
    public int maxIceCream(int[] arr, int coins) {
        Arrays.sort(arr);
        int count=0;
        int sum =0;
        if(arr[0]>coins) return 0;
        for( int num:arr){
            if(num<coins && sum+num<=coins){
                count++;
                sum+=num;
            }
            if(sum >=coins) break;
            
        }

        return count;
    }
}