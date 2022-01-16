class Solution {
 public:
  bool checkValid(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
      bitset<101> row, col;

      for (int j = 0; j < n; ++j) {
        row[matrix[i][j]] = 1;
        col[matrix[j][i]] = 1;
      }

      if (min(row.count(), col.count()) < n) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 190 ms, faster than 65.27%
// Memory Usage: 34.9 MB, less than 77.55%
// 2022.1.16 at 茗筑美嘉