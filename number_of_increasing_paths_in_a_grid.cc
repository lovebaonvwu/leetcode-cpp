class Solution {
  int m;
  int n;
  int dirs[5] = {1, 0, -1, 0, 1};
  int mod = 1e9 + 7;
  vector<vector<int>> dp;

 public:
  int countPaths(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    dp.resize(m, vector<int>(n));

    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = (ans + dfs(grid, i, j)) % mod;
    return ans;
  }

  int dfs(const vector<vector<int>>& g, int i, int j) {
    if (dp[i][j] > 0) {
      return dp[i][j];
    }

    int cnt = 1;
    for (int k = 0; k < 4; ++k) {
      int y = i + dirs[k];
      int x = j + dirs[k + 1];

      if (y < 0 || y == m || x < 0 || x == n || g[i][j] >= g[y][x]) {
        continue;
      }

      cnt = (cnt + dfs(g, y, x)) % mod;
    }

    return dp[i][j] = cnt;
  }
};
// Runtime 304 ms
// Memory 43.6 MB