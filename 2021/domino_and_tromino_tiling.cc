class Solution {
 public:
  int numTilings(int n) {
    int mod = 1e9 + 7;

    vector<vector<long>> dp(n + 1, vector<long>(2));
    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
      dp[i][0] = (2 * dp[i - 1][1] + dp[i - 2][0] + dp[i - 1][0]) % mod;
      dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % mod;
    }

    return dp[n][0];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 17.03%
// 2021.12.10 at 奥盛大厦