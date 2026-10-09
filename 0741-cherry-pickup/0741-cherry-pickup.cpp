
class Solution {
public:
    int cherryPickup(vector<vector<int>>& arr) {
        int n = arr.size();

        int dp[51][51][51];

        // Initialize all states as invalid
        for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
                for (int k = 0; k < 51; k++)
                    dp[i][j][k] = -1e9;

        dp[n-1][n-1][n-1] = arr[n-1][n-1];

        for (int r1 = n-1; r1 >= 0; r1--) {
            for (int c1 = n-1; c1 >= 0; c1--) {
                for (int r2 = n-1; r2 >= 0; r2--) {

                    int c2 = r1 + c1 - r2;

                    if (r2 >= n || c2 < 0 || c2 >= n)
                        continue;

                    if (arr[r1][c1] == -1 ||
                        arr[r2][c2] == -1)
                        continue;

                    if (r1 == n-1 && c1 == n-1)
                        continue;

                    int cherries = arr[r1][c1];

                    if (r1 != r2)
                        cherries += arr[r2][c2];

                    int a = -1e9, b = -1e9;
                    int c = -1e9, d = -1e9;

                    if (c1+1 < n)
                        a = dp[r1][r2][c1+1];

                    if (r1+1 < n)
                        b = dp[r1+1][r2][c1];

                    if (r2+1 < n)
                        c = dp[r1][r2+1][c1+1];

                    if (r1+1 < n && r2+1 < n)
                        d = dp[r1+1][r2+1][c1];

                    dp[r1][r2][c1] =
                        cherries + max({a, b, c, d});
                }
            }
        }

        return max(0, dp[0][0][0]);
    }
};
