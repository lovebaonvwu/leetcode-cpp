class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) {
      return 0;
    }

    int n = grid[0].size();

    if (n == 0) {
      return 0;
    }

    vector<int> prev(n);
    vector<int> cur(n);

    prev[0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
      prev[i] = grid[0][i] + prev[i - 1];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == 0) {
          cur[j] = grid[i][j] + prev[j];
        } else {
          cur[j] = grid[i][j] + min(cur[j - 1], prev[j]);
        }
      }

      swap(prev, cur);
    }

    return prev[n - 1];
  }
};
// Runtime: 8 ms, faster than 88.42%
// Memory Usage: 10.4 MB, less than 100.00%

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) {
      return 0;
    }

    int n = grid[0].size();

    if (n == 0) {
      return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
      dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < m; ++i) {
      dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
      }
    }

    return dp[m - 1][n - 1];
  }
};
// Runtime: 8 ms, faster than 88.42%
// Memory Usage: 10.9 MB, less than 52.63%