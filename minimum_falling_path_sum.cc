class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
      dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; ++i) {
      dp[i][0] = matrix[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
      dp[i][n - 1] = matrix[i][n - 1] + min(dp[i - 1][n - 1], dp[i - 1][n - 2]);

      for (int j = 1; j < n - 1; ++j) {
        dp[i][j] = matrix[i][j] +
                   min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
      }
    }

    return *min_element(dp.back().begin(), dp.back().end());
  }
};
// Runtime: 8 ms, faster than 95.87%
// Memory Usage: 9.8 MB, less than 22.92%
// 2021.8.4 at 奥盛大厦