class Solution {
  int ans = 0;
  int m;
  int n;

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          ans = max(ans, dfs(grid, i, j));
        }
      }
    }

    return ans;
  }

  int dfs(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
      return 0;
    }

    if (!g[i][j]) {
      return 0;
    }

    g[i][j] = 0;

    int sum = 1;

    sum += dfs(g, i, j + 1);
    sum += dfs(g, i, j - 1);
    sum += dfs(g, i + 1, j);
    sum += dfs(g, i - 1, j);

    return sum;
  }
};
// Runtime: 40 ms, faster than 42.80%
// Memory Usage: 23.2 MB, less than 81.75%

class Solution {
  int m;
  int n;

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          ans = max(ans, dfs(grid, i, j));
        }
      }
    }

    return ans;
  }

  int dfs(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
      return 0;
    }

    if (!g[i][j]) {
      return 0;
    }

    g[i][j] = 0;

    int sum = 1;

    sum += dfs(g, i, j + 1);
    sum += dfs(g, i, j - 1);
    sum += dfs(g, i + 1, j);
    sum += dfs(g, i - 1, j);

    return sum;
  }
};
// Runtime: 36 ms, faster than 57.17%
// Memory Usage: 23.2 MB, less than 82.45%