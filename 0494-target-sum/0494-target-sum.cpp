
class Solution {
    int dp[21][2501];

    int solve(vector<int>& arr, int target, int i) {
        if (i == 0)
            return target == 0 ? 1 : 0;

        if (target < -1500 || target > 1000) return 0;

        if (dp[i][target + 1500] != -1)
            return dp[i][target + 1500];

        int take = solve(arr, target - arr[i-1], i-1);
        int ntake = solve(arr, target + arr[i-1], i-1);

        return dp[i][target + 1500] = take + ntake;
    }

public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (abs(target) > sum) return 0;

        // if (n == 0) return target == 0 ? 1 : 0;

        memset(dp, -1, sizeof(dp));
        return solve(arr, target, n);
    }
};
