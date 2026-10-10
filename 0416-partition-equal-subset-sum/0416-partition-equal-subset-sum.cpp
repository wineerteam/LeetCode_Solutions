class Solution {
    bool solve(vector<int>& arr, int tar, int i,
               vector<vector<int>>& dp) {

        if (tar == 0) return true;
        if (tar < 0 || i >= arr.size()) return false;

        if (dp[i][tar] != -1)
            return dp[i][tar];

        bool take = solve(arr, tar - arr[i], i + 1, dp);
        bool ntake = solve(arr, tar, i + 1, dp);

        return dp[i][tar] = take || ntake;
        
    }

public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(arr, target, 0, dp);
    }
};