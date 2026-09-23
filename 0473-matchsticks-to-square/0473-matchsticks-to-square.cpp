#define ll long long

class Solution {
    int n;
    ll target;

    bool solve(vector<int>& arr, int idx,
               vector<ll>& sides) {

        // All sticks used
        if (idx == n)
            return true;

        for (int i = 0; i < 4; i++) {

            // Same state already tried
            if (i > 0 && sides[i] == sides[i - 1])
                continue;

            // Cannot exceed target
            if (sides[i] + arr[idx] > target)
                continue;

            // Take
            sides[i] += arr[idx];

            if (solve(arr, idx + 1, sides))
                return true;

            // Backtrack
            sides[i] -= arr[idx];

            // If putting this stick into an empty side
            // doesn't work, other empty sides are identical
            if (sides[i] == 0)
                break;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& arr) {

        n = arr.size();

        if (n < 4)
            return false;

        ll sum = accumulate(
            arr.begin(),
            arr.end(),
            0LL
        );

        if (sum % 4 != 0)
            return false;

        target = sum / 4;

        // Large sticks first
        sort(arr.rbegin(), arr.rend());

        // Optional quick check
        if (arr[0] > target)
            return false;

        vector<ll> sides(4, 0);

        return solve(arr, 0, sides);
    }
};