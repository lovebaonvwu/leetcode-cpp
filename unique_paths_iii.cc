class Solution {
  int ans = 0;

 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n));
    int empty = 0;
    int si = -1;
    int sj = -1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        visited[i][j] = grid[i][j];

        if (grid[i][j] == 0) {
          ++empty;
        }

        if (grid[i][j] == 1) {
          si = i;
          sj = j;
        }
      }
    }

    dfs(grid, visited, empty, si, sj + 1);
    dfs(grid, visited, empty, si, sj - 1);
    dfs(grid, visited, empty, si + 1, sj);
    dfs(grid, visited, empty, si - 1, sj);

    return ans;
  }

  void dfs(vector<vector<int>>& g,
           vector<vector<int>> v,
           int empty,
           int i,
           int j) {
    if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size()) {
      return;
    }

    if (g[i][j] == 2 && empty == 0) {
      ++ans;
      return;
    }

    if (v[i][j] == -1 || v[i][j] == 1 || v[i][j] == 2) {
      return;
    }

    if (v[i][j] == 0) {
      v[i][j] = -1;
    }

    dfs(g, v, empty - 1, i, j + 1);
    dfs(g, v, empty - 1, i, j - 1);
    dfs(g, v, empty - 1, i + 1, j);
    dfs(g, v, empty - 1, i - 1, j);
  }
};
// Runtime: 148 ms, faster than 12.14%
// Memory Usage: 80 MB, less than 10.36%