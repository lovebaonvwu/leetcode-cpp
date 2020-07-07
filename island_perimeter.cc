class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    size_t m = grid.size();

    if (m == 0) {
      return 0;
    }

    size_t n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          if (i > 0 && grid[i - 1][j]) {
            ++ans;
          }

          if (j > 0 && grid[i][j - 1]) {
            ++ans;
          }
        } else {
          if (i == 0) {
            ++ans;
          }
          if (i > 0 && !grid[i - 1][j]) {
            ++ans;
          }

          if (j == 0) {
            ++ans;
          }

          if (j > 0 && !grid[i][j - 1]) {
            ++ans;
          }

          if (i == m - 1) {
            ++ans;
          }

          if (j == n - 1) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 93.91%
// Memory Usage: 15.4 MB, less than 100.00%

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int cnt = 0;
    int dup = 0;

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j]) {
          ++cnt;

          if (i > 0 && grid[i - 1][j])
            ++dup;
          if (j > 0 && grid[i][j - 1])
            ++dup;
        }
      }
    }

    return 4 * cnt - 2 * dup;
  }
};
// Runtime: 352 ms, faster than 7.41%
// Memory Usage: 96 MB, less than 91.86%