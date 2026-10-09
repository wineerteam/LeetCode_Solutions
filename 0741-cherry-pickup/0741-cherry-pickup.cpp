
class Solution {
    int n, m;
    int  dp[51][51][51];

    int solve(vector<vector<int>>& arr, int r1, int r2, int c1) {

        int c2 = r1 + c1 - r2;

        if (r1 >= n || r2 >= n || c1 >= m || c2 >= m)
            return -1e9;

        if (arr[r1][c1] == -1 || arr[r2][c2] == -1)
            return -1e9;

            if( dp[r1][r2][c1] !=-1) return dp[r1][r2][c1];

        if (r1 == n - 1 && c1 == m - 1 )
            return arr[r1][c1];

        int ans = arr[r1][c1];

        if (r1 != r2 )
            ans += arr[r2][c2];

        int a = solve(arr, r1, r2, c1 + 1);
        int b = solve(arr, r1 + 1, r2, c1);
        int c = solve(arr, r1, r2 + 1, c1 + 1);
        int d = solve(arr, r1 + 1, r2 + 1, c1);

        return dp[r1][r2][c1]= ans + max({a, b, c, d});
    }

public:
    int cherryPickup(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        memset(dp,-1,sizeof(dp));

        return  max(0,solve(arr, 0, 0, 0));

        
    }
};
