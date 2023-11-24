class Solution {
 public:
  int twoEggDrop(int n) {
    vector<vector<int>> dp(3, vector<int>(n + 1, INT_MAX));

    iota(dp[1].begin(), dp[1].end(), 0);
    dp[0][0] = dp[2][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[2][i] = min(dp[2][i], 1 + max(dp[1][j - 1], dp[2][i - j]));
      }
    }

    return dp[2][n];
  }
};
// Runtime 238 ms
// Memory 7.2 MB