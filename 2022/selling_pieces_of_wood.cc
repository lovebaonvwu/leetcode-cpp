class Solution {
  long long dp[201][201];

 public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    for (auto& p : prices) {
      dp[p[0]][p[1]] = p[2];
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k < i; ++k) {
          dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
        }

        for (int k = 1; k < j; ++k) {
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 328 ms, faster than 75.29%
// Memory Usage: 25 MB, less than 87.34%
// 2022.8.2 at 奥盛大厦