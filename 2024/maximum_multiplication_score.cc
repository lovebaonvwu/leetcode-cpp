class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(n, vector<long long>(4));
        dp[0][0] = 1LL * b[0] * a[0];

        dp[1][0] = max(dp[0][0], 1LL * b[1] * a[0]);
        dp[1][1] = dp[0][0] + 1LL * b[1] * a[1];

        dp[2][0] = max(dp[1][0], 1LL * b[2] * a[0]);
        dp[2][1] = max(dp[1][1], dp[1][0] + 1LL * b[2] * a[1]);
        dp[2][2] = dp[1][1] + 1LL * b[2] * a[2];

        dp[3][0] = max(dp[2][0], 1LL * b[3] * a[0]);
        dp[3][1] = max(dp[2][1], dp[2][0] + 1LL * b[3] * a[1]);
        dp[3][2] = max(dp[2][2], dp[2][1] + 1LL * b[3] * a[2]);
        dp[3][3] = dp[2][2] + 1LL * b[3] * a[3];

        long long ans = dp[3][3];

        for (int i = 4; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], 1LL * b[i] * a[0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1LL * b[i] * a[1]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + 1LL * b[i] * a[2]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + 1LL * b[i] * a[3]);

            ans = max(ans, dp[i][3]);
        }

        return ans;

    }
};
// 335 ms
// 230.27 MB