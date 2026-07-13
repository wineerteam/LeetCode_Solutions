
import java.util.ArrayList;
import java.util.List;

// Solution Class
class Solution {
  // Method to find a sorted list of all the integers in the range [low, high]
  // inclusive that have sequential digits
  public List<Integer> sequentialDigits(int low, int high) {
    // Initialize the list of integer for the result
    ArrayList<Integer> result = new ArrayList<>();

    // Initialize the lowDigit and highDigit
    int lowDigit = String.valueOf(low).length();
    int highDigit = String.valueOf(high).length();

    // Iterate over the range of the lowDigit and highDigit
    for (int digits = lowDigit; digits <= highDigit; digits++) {
      // Iterate over the range 1 to 10
      for (int start = 1; start < 10; start++) {
        // If start + digits are more than the 10 then break out of the loop
        if (start + digits > 10) {
          break;
        }

        // Initialize the number and previous variable
        int number = start;
        int previous = start;

        // Form the number
        for (int i = 1; i < digits; i++) {
          number = number * 10 + (++previous);
        }

        // In number is in the range low and high then add it to the result
        if (number >= low && number <= high) {
          result.add(number);
        }
      }
    }

    // Return the result variable
    return result;
  }
}

public class _1291_Sequential_Digits {
  // Main method to test sequentialDigits
  public static void main(String[] args) {
    int low = 1000;
    int high = 13000;

    List<Integer> result = new Solution().sequentialDigits(low, high);

    System.out.println(
        "A sorted list of all the integers in the range [" + low
            + ", " + high + "] inclusive that have sequential digits are : "
            + result);
  }
}