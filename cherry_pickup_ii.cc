class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(n, -1)));

    dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];

    int ans = 0;
    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          int cherry = j == k ? grid[i][j] : grid[i][j] + grid[i][k];

          for (int c1 = j - 1; c1 <= j + 1; ++c1) {
            for (int c2 = k - 1; c2 <= k + 1; ++c2) {
              if (c1 >= 0 && c1 < n && c2 >= 0 && c2 < n &&
                  dp[i - 1][c1][c2] >= 0) {
                dp[i][j][k] = max(dp[i][j][k], cherry + dp[i - 1][c1][c2]);
                if (i == m - 1) {
                  ans = max(ans, dp[i][j][k]);
                }
              }
            }
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 132 ms, faster than 27.49%
// Memory Usage: 14.8 MB, less than 28.83%

class Solution {
  int m;
  int n;
  int mem[71][71][71];

 public:
  int cherryPickup(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    memset(mem, -1, sizeof(mem));

    return dfs(grid, 0, 0, n - 1);
  }

  int dfs(vector<vector<int>>& g, int i, int j, int k) {
    if (i < 0 || i == m || j < 0 || j == n || k < 0 || k == n) {
      return 0;
    }

    int& val = mem[i][j][k];

    if (val != -1) {
      return val;
    }

    for (int c1 = j - 1; c1 <= j + 1; ++c1) {
      for (int c2 = k - 1; c2 <= k + 1; ++c2) {
        val = max(val, dfs(g, i + 1, c1, c2));
      }
    }

    val += j == k ? g[i][j] : g[i][j] + g[i][k];

    return val;
  }
};
// Runtime: 48 ms, faster than 89.90%
// Memory Usage: 10.2 MB, less than 74.45%