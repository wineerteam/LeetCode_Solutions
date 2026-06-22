import java.util.*;

class Solution {
    public int maxNumberOfBalloons(String text) {
        // Required frequency of each character in "balloon"
        Map<Character, Integer> map = new HashMap<>();
        map.put('b', 1);
        map.put('a', 1);
        map.put('l', 2);
        map.put('o', 2);
        map.put('n', 1);

        // Count characters from input text
        Map<Character, Integer> inArray = new HashMap<>();
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (map.containsKey(ch)) {
                inArray.put(ch, inArray.getOrDefault(ch, 0) + 1);
            }
        }

        int result = Integer.MAX_VALUE;

        // Compare available counts with required counts
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            char ch = entry.getKey();
            int required = entry.getValue();
            int available = inArray.getOrDefault(ch, 0);

            result = Math.min(result, available / required);
        }

        return result;
    }
}