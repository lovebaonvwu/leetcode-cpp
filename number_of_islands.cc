class Solution {
  int m;
  int n;

 public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;

    m = grid.size();
    if (!m) {
      return ans;
    }

    n = grid[0].size();
    if (!n) {
      return ans;
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j);
        }
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>>& g, int i, int j) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
      return;
    }

    if (g[i][j] == '0') {
      return;
    }

    g[i][j] = '0';
    dfs(g, i + 1, j);
    dfs(g, i - 1, j);
    dfs(g, i, j + 1);
    dfs(g, i, j - 1);
  }
};
// Runtime: 48 ms, faster than 18.11%
// Memory Usage: 9.7 MB, less than 63.16%