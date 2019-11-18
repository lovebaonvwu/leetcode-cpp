class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m));

    k %= (m * n);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int p = (i * m + j + k) % (m * n);

        ans[p / m][p % m] = grid[i][j];
      }
    }

    return ans;
  }
};
// Runtime: 92 ms, faster than 33.33%
// Memory Usage: 13.2 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    k %= (m * n);

    while (k-- > 0) {
      int prev = grid[n - 1][m - 1];

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int tmp = grid[i][j];

          grid[i][j] = prev;

          prev = tmp;
        }
      }
    }

    return grid;
  }
};
// Runtime: 80 ms, faster than 50.00%
// Memory Usage: 13.4 MB, less than 100.00%