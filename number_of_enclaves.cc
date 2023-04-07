class Solution {
  int m;
  int n;

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int j = 0; j < n; ++j) {
      if (grid[0][j] == 1) {
        dfs(grid, 0, j);
      }

      if (grid[m - 1][j] == 1) {
        dfs(grid, m - 1, j);
      }
    }

    for (int i = 0; i < m; ++i) {
      if (grid[i][0] == 1) {
        dfs(grid, i, 0);
      }

      if (grid[i][n - 1] == 1) {
        dfs(grid, i, n - 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += grid[i][j] == 1;
      }
    }

    return ans;
  }

  void dfs(vector<vector<int>>& g, int y, int x) {
    g[y][x] = 0;

    int dirs[] = {1, 0, -1, 0, 1};

    for (int k = 0; k < 4; ++k) {
      int dy = y + dirs[k];
      int dx = x + dirs[k + 1];

      if (dy < 0 || dy == m || dx < 0 || dx == n) {
        continue;
      }

      if (g[dy][dx] != 1) {
        continue;
      }

      dfs(g, dy, dx);
    }
  }
};
// Runtime 73 ms
// Memory 42.5 MB