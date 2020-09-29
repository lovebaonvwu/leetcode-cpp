class Solution {
  int m = 0;
  int n = 0;
  long ans = LONG_MIN;

 public:
  int maxProductPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    dfs(grid, 0, 0, 1);

    ans %= (int)(1e9 + 7);

    return max<long>(-1, ans);
  }

  void dfs(vector<vector<int>>& g, int i, int j, long p) {
    if (i >= m || j >= n) {
      return;
    }

    if (i == m - 1 && j == n - 1) {
      ans = max<long>(ans, p * g[i][j]);
      return;
    }

    dfs(g, i + 1, j, p * g[i][j]);
    dfs(g, i, j + 1, p * g[i][j]);
  }
};
// Time Limit Exceeded

class Solution {
  int m = 0;
  int n = 0;
  long ans = LONG_MIN;

 public:
  int maxProductPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    dfs(grid, 0, 0, 1);

    ans %= (int)(1e9 + 7);

    return max<long>(-1, ans);
  }

  void dfs(vector<vector<int>>& g, int i, int j, long p) {
    if (i >= m || j >= n) {
      return;
    }

    if (i == m - 1 && j == n - 1) {
      ans = max<long>(ans, p * g[i][j]);
      return;
    }

    if (g[i][j] == 0) {
      ans = max<long>(ans, 0);
      return;
    }

    dfs(g, i + 1, j, p * g[i][j]);
    dfs(g, i, j + 1, p * g[i][j]);
  }
};
// Runtime: 1648 ms, faster than 5.01%
// Memory Usage: 10.1 MB, less than 74.11%

class Solution {
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    long ans = LONG_MIN;

    vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n));

    dp[0][0].first = grid[0][0];
    dp[0][0].second = grid[0][0];

    for (int i = 1; i < m; ++i) {
      if (grid[i][0] > 0) {
        dp[i][0].first = grid[i][0] * dp[i - 1][0].first;
        dp[i][0].second = grid[i][0] * dp[i - 1][0].second;
      } else if (grid[i][0] < 0) {
        dp[i][0].first = grid[i][0] * dp[i - 1][0].second;
        dp[i][0].second = grid[i][0] * dp[i - 1][0].first;
      }
    }

    for (int j = 1; j < n; ++j) {
      if (grid[0][j] > 0) {
        dp[0][j].first = grid[0][j] * dp[0][j - 1].first;
        dp[0][j].second = grid[0][j] * dp[0][j - 1].second;
      } else if (grid[0][j] < 0) {
        dp[0][j].first = grid[0][j] * dp[0][j - 1].second;
        dp[0][j].second = grid[0][j] * dp[0][j - 1].first;
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (grid[i][j] > 0) {
          dp[i][j].first =
              grid[i][j] * max<long>(dp[i][j - 1].first, dp[i - 1][j].first);
          dp[i][j].second =
              grid[i][j] * min<long>(dp[i][j - 1].second, dp[i - 1][j].second);
        } else if (grid[i][j] < 0) {
          dp[i][j].first =
              grid[i][j] * min<long>(dp[i][j - 1].second, dp[i - 1][j].second);
          dp[i][j].second =
              grid[i][j] * max<long>(dp[i][j - 1].first, dp[i - 1][j].first);
        }
      }
    }

    dp[m - 1][n - 1].first %= 1000000007;

    return max<long>(-1, dp[m - 1][n - 1].first);
  }
};
// Runtime: 4 ms, faster than 99.54%
// Memory Usage: 10.5 MB, less than 36.38%