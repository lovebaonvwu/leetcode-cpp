class Solution {
    vector<int> buildPrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i <= n; ++i) {
            if (primes[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }

long long dp[10005][15];

public:
    int idealArrays(int n, int maxValue) {
        vector<int> primes = buildPrimes(maxValue);

        int mod = 1e9 + 7;
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;

            for (int j = 1; j <= 14; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }

        long long ans = 0;

        for (int i = 1; i <= maxValue; ++i) {
            int v = i;
            long long sum = 1;

            for (auto p : primes) {
                long long count = 0;
                while (v > 1 && (v % p == 0)) {
                    ++count;
                    v /= p;
                }

                sum = (sum * dp[n][count]) % mod;
            }

            ans = (ans + sum) % mod;
        }

        return ans;
    }
};

// Time: O(n * 14 * 14)
// Space: O(n * log(maxValue))