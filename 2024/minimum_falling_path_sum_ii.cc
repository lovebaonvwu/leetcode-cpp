class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
      dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int val = INT_MAX;
        for (int k = 0; k < n; ++k) {
          if (k == j)
            continue;
          val = min(val, dp[i - 1][k]);
        }

        dp[i][j] = grid[i][j] + val;
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
      ans = min(ans, dp[n - 1][j]);
    }

    return ans;
  }
};
// 127 ms
// 18.26 MB

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n));
    int p = -1, q = -1;
    for (int j = 0; j < n; ++j) {
      dp[0][j] = grid[0][j];

      if (p == -1) {
        p = j;
      } else if (grid[0][j] < grid[0][p]) {
        q = p;
        p = j;
      } else if (q == -1 || grid[0][j] < grid[0][q]) {
        q = j;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == p) {
          dp[i][j] = grid[i][j] + dp[i - 1][q];
        } else {
          dp[i][j] = grid[i][j] + dp[i - 1][p];
        }
      }

      p = -1;
      q = -1;

      for (int j = 0; j < n; ++j) {
        if (p == -1) {
          p = j;
        } else if (dp[i][j] < dp[i][p]) {
          q = p;
          p = j;
        } else if (q == -1 || dp[i][j] < dp[i][q]) {
          q = j;
        }
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; ++j) {
      ans = min(ans, dp[n - 1][j]);
    }

    return ans;
  }
};
// 26 ms
// 18.27 MB