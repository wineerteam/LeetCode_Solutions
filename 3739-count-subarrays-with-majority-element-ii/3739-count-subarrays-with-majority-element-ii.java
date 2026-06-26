import java.util.*;

class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i] == target ? 1 : -1;
        }

        int[] pref = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        int[] sorted = pref.clone();
        Arrays.sort(sorted);

        Map<Integer, Integer> map = new HashMap<>();
        int idx = 1;
        for (int v : sorted) {
            if (!map.containsKey(v)) {
                map.put(v, idx++);
            }
        }

        Fenwick fenwick = new Fenwick(idx + 2);

        long ans = 0;

        for (int v : pref) {
            int id = map.get(v);
            ans += fenwick.query(id - 1);
            fenwick.update(id, 1);
        }

        return ans;
    }

    class Fenwick {
        int[] tree;

        Fenwick(int n) {
            tree = new int[n];
        }

        void update(int i, int val) {
            while (i < tree.length) {
                tree[i] += val;
                i += i & -i;
            }
        }

        int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= i & -i;
            }
            return sum;
        }
    }
}