class Solution {
 public:
  int maxScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = INT_MIN;
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN / 2));
    for (int j = n - 2; j >= 0; --j) {
      dp[m - 1][j] = max(dp[m - 1][j + 1] + grid[m - 1][j + 1] - grid[m - 1][j],
                         grid[m - 1][j + 1] - grid[m - 1][j]);
      ans = max(ans, dp[m - 1][j]);
    }

    for (int i = m - 2; i >= 0; --i) {
      dp[i][n - 1] = max(dp[i + 1][n - 1] + grid[i + 1][n - 1] - grid[i][n - 1],
                         grid[i + 1][n - 1] - grid[i][n - 1]);
      ans = max(ans, dp[i][n - 1]);
    }

    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j] + grid[i + 1][j] - grid[i][j]);
        dp[i][j] = max(dp[i][j], dp[i][j + 1] + grid[i][j + 1] - grid[i][j]);
        dp[i][j] = max(dp[i][j], grid[i + 1][j] - grid[i][j]);
        dp[i][j] = max(dp[i][j], grid[i][j + 1] - grid[i][j]);
        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};
// 133 ms
// 62.40 MB