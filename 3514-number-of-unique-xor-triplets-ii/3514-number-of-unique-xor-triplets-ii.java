public class Solution {
    public int uniqueXorTriplets(int[] nums) {
        // Maximum element value is 1500, next power of 2 is 2048
        final int MAX_VAL = 2048; 
        
        // Track unique numbers present in the input array
        boolean[] hasNum = new boolean[MAX_VAL];
        for (int num : nums) {
            hasNum[num] = true;
        }
        
        // Track all unique pairs (nums[i] ^ nums[j])
        boolean[] hasPair = new boolean[MAX_VAL];
        for (int i = 0; i < MAX_VAL; i++) {
            if (!hasNum[i]) continue;
            for (int j = i; j < MAX_VAL; j++) {
                if (!hasNum[j]) continue;
                hasPair[i ^ j] = true;
            }
        }
        
        // Track all unique triplets (Pair_XOR ^ nums[k])
        boolean[] hasTriplet = new boolean[MAX_VAL];
        int uniqueTripletCount = 0;
        
        for (int pairXor = 0; pairXor < MAX_VAL; pairXor++) {
            if (!hasPair[pairXor]) continue;
            for (int k = 0; k < MAX_VAL; k++) {
                if (!hasNum[k]) continue;
                
                int tripletXor = pairXor ^ k;
                if (!hasTriplet[tripletXor]) {
                    hasTriplet[tripletXor] = true;
                    uniqueTripletCount++;
                }
            }
        }
        
        return uniqueTripletCount;
    }
}