class Solution {
    int n, m;
    int dp[201][201];

    int solve(vector<vector<int>>& arr, int i, int j) {

        if(i == n-1 && j == m-1)
            return arr[i][j];

        if(i >= n || j >= m)
            return INT_MAX;

            if( dp[i][j] !=0)return dp[i][j];

        int take = solve(arr, i+1, j);
        int ntake = solve(arr, i, j+1);

        return dp[i][j]= arr[i][j] + min(take, ntake);
    }

public:
    int minPathSum(vector<vector<int>>& arr) {

        n = arr.size();
        m = arr[0].size();

        memset(dp,0,sizeof(dp));

        return solve(arr, 0, 0);
    }
};