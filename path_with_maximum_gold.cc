class Solution {
  int ans = 0;
  int m = 0;
  int n = 0;

  vector<int> dirs = {0, -1, 0, 1, 0};

 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          visited[i][j] = true;

          dfs(grid, visited, i, j, grid[i][j]);

          visited[i][j] = false;
        }
      }
    }

    return ans;
  }

  void dfs(vector<vector<int>>& g,
           vector<vector<bool>>& v,
           int x,
           int y,
           int gold) {
    ans = max(ans, gold);

    for (int i = 0; i < 4; ++i) {
      int dx = x + dirs[i];
      int dy = y + dirs[i + 1];

      if (dx < 0 || dy < 0 || dx == m || dy == n) {
        continue;
      }

      if (v[dx][dy] || g[dx][dy] == 0) {
        continue;
      }

      v[dx][dy] = true;

      dfs(g, v, dx, dy, gold + g[dx][dy]);

      v[dx][dy] = false;
    }
  }
};
// Runtime: 60 ms, faster than 80.34%
// Memory Usage: 7.6 MB, less than 66.40%

class Solution {
  int m = 0;
  int n = 0;

  vector<int> dirs = {0, -1, 0, 1, 0};

 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans = max(ans, dfs(grid, i, j));
      }
    }

    return ans;
  }

  int dfs(vector<vector<int>>& g, int x, int y) {
    if (x < 0 || y < 0 || x == m || y == n || g[x][y] <= 0) {
      return 0;
    }

    g[x][y] = -g[x][y];

    int res = 0;

    for (int i = 0; i < 4; ++i) {
      res = max(res, dfs(g, x + dirs[i], y + dirs[i + 1]));
    }

    g[x][y] = -g[x][y];

    return res + g[x][y];
  }
};
// Runtime: 64 ms, faster than 75.57%
// Memory Usage: 7.4 MB, less than 85.80%