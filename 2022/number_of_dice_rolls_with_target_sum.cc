class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= min(k, target); ++i) {
      dp[1][i] = 1;
    }

    int mod = 1e9 + 7;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= target; ++j) {
        for (int m = 1; m <= k; ++m) {
          if (m <= j) {
            dp[i][j] = (dp[i - 1][j - m] + dp[i][j]) % mod;
          }
        }
      }
    }

    return dp[n][target];
  }
};
// Runtime: 212 ms, faster than 5.72%
// Memory Usage: 8.5 MB, less than 28.55%
// 2022.10.2 at 茗筑美嘉