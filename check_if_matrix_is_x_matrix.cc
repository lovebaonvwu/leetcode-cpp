class Solution {
 public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || j == (n - 1 - i)) {
          if (grid[i][j] == 0) {
            return false;
          }
        } else {
          if (grid[i][j] > 0) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
// Runtime: 89 ms, faster than 12.84%
// Memory Usage: 16.4 MB, less than 42.99%
// 2022.10.1 at 茗筑美嘉