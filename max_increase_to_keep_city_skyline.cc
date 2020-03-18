class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<int> row(m);
    vector<int> col(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
      }
    }

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += min(row[i], col[j]) - grid[i][j];
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 99.06%
// Memory Usage: 8.5 MB, less than 100.00%