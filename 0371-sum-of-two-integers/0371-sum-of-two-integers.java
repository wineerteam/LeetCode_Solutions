class Solution {
    public int getSum(int a, int b) {
        
        while( b !=0){
         int temp = (a&b)<<1;
             a=a^b;
             b=temp;

        }
        return a;
    }
}

// 1. simple math a+b no extra space no time 
// 2. bitmanipulation use oR opertors find additions
