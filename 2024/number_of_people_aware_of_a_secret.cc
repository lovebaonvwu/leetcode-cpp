class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n);
        dp[0] = 1;
        int mod = 1e9 + 7;

        for (int i = 0; i + delay < n; ++i) {
            for (int j = i + delay; j < min(i + forget, n); ++j) {
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i + forget > n - 1)
                ans = (ans + dp[i]) % mod;
        }

        return ans;
    }
};
// 9 ms
// 9.55 MB
