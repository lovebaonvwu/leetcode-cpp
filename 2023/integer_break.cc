class Solution {
  vector<vector<int>> dp;

 public:
  int integerBreak(int n) {
    dp.resize(n + 1, vector<int>(60, -1));
    return dfs(n, 0, 1);
  }

  int dfs(int n, int k, int val) {
    if (n == 0 && k >= 2) {
      return 1;
    }

    if (dp[n][k] != -1) {
      return dp[n][k];
    }

    for (int i = 1; i <= n; ++i) {
      dp[n][k] = max(dp[n][k], i * dfs(n - i, k + 1, val * i));
    }

    return dp[n][k];
  }
};
// 4ms
// 6.88MB