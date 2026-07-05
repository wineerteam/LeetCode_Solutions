class Solution {

    public String longestPalindrome(String s) {

        // Edge case
        if (s == null || s.length() == 0)
            return "";

        // Step 1: Transform string
        char[] T = preprocess(s);

        // Step 2: P[i] stores palindrome radius
        int[] P = new int[T.length];

        // Current Center and Right Boundary
        int C = 0;
        int R = 0;

        // Step 3: Traverse transformed string
        for (int i = 1; i < T.length - 1; i++) {

            // Mirror index
            int mirr = 2 * C - i;

            // Copy information from mirror if inside boundary
            if (i < R) {
                P[i] = Math.min(R - i, P[mirr]);
            }

            // Expand palindrome
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }

            // Update center and right boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Step 4: Find maximum palindrome
        int maxLen = 0;
        int center = 0;

        for (int i = 1; i < P.length - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                center = i;
            }
        }

        // Step 5: Convert transformed index to original string index
        int start = (center - maxLen) / 2;

        return s.substring(start, start + maxLen);
    }

    // Transform string
    // Example:
    // "abba"
    // ->
    // "$#a#b#b#a#@"
    private char[] preprocess(String s) {

        char[] T = new char[2 * s.length() + 3];

        T[0] = '$';

        int index = 1;

        for (int i = 0; i < s.length(); i++) {
            T[index++] = '#';
            T[index++] = s.charAt(i);
        }

        T[index++] = '#';
        T[index] = '@';

        return T;
    }
}