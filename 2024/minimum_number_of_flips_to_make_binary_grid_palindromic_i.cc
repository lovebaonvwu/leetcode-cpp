class Solution {
 public:
  int minFlips(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int row_cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0, k = n - 1; j < k; ++j, --k) {
        if (grid[i][j] != grid[i][k]) {
          ++row_cnt;
        }
      }
    }

    int col_cnt = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 0, k = m - 1; i < k; ++i, --k) {
        if (grid[i][j] != grid[k][j]) {
          ++col_cnt;
        }
      }
    }

    return min(row_cnt, col_cnt);
  }
};
// 295 ms
// 181.58 MB