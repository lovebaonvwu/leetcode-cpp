class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 45.31%

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }

    vector<int> prev(n, 1);
    vector<int> cur(n, 1);

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        cur[j] = cur[j - 1] + prev[j];
      }

      swap(cur, prev);
    }

    return prev[n - 1];
  }
};
// Runtime: 4 ms, faster than 54.58%
// Memory Usage: 8.3 MB, less than 82.81%

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};
// Runtime: 4 ms, faster than 54.58%
// Memory Usage: 8.8 MB, less than 28.13%