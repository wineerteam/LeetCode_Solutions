long long M = 1e9 + 7;
long long N = 1e5 + 1;

vector<long long> fact(N + 1, 1);
vector<long long> frmt(N + 1, 1);

class Solution {

    // Find Power using Binary Exponentiation
    long long findpwr(long long a, long long b) {

        if(b == 0) return 1;

        long long half = findpwr(a, b / 2) % M;

        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    // Find nCr
    long long ncr(long long a, long long b) {

        if(b < 0 || b > a) return 0;

        return fact[a] * frmt[a - b] % M * frmt[b] % M;
    }

public:

    int countGoodArrays(int n, int m, int k) {

        // (n-1)Ck * m * (m-1)^(n-k-1)

        // Factorial Precompute
        fact[0] = 1;
        fact[1] = 1;

        for(int i = 2; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
        }


        // Fermat's Little Theorem

        // Only calculate inverse of fact[n]
        frmt[n] = findpwr(fact[n], M - 2);

        // Calculate remaining inverse factorials
        for(int i = n; i >= 1; i--) {
            frmt[i - 1] = (frmt[i] * i) % M;
        }


        long long ans = ncr(n - 1, k);

        ans = (ans * m) % M;

        ans = ans * findpwr(m - 1, n - k - 1) % M;

        return ans;
    }
};