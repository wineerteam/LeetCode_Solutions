#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> prime(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> pr;

        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) pr.push_back(i);
        }

        return pr;
    }

public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> pr = prime(n);

        // dp[sum] stores the best subset for that exact sum
        vector<vector<int>> dp(s + 1);
        vector<bool> vis(s + 1, false);
        vis[0] = true;

        for (int p : pr) {
            for (int sum = s; sum >= p; sum--) {
                if (!vis[sum - p]) continue;

                vector<int> take = dp[sum - p];
                take.push_back(p);

                if (!vis[sum] ||
                    take.size() < dp[sum].size() ||
                    (take.size() == dp[sum].size() && take < dp[sum])) {
                    dp[sum] = take;
                }

                vis[sum] = true;
            }
        }

        for (int sum = s; sum >= 1; sum--) {
            if (vis[sum]) return dp[sum];
        }

        return {};
    }
};