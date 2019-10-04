class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }

    int m = matrix.size();
    int n = matrix[0].size();

    bool first_row_contain_zero = false;
    for (int i = 0; i < n; ++i) {
      if (matrix[0][i] == 0) {
        first_row_contain_zero = true;
        break;
      }
    }

    for (int i = 1; i < m; ++i) {
      bool cur_row_contain_zero = false;

      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          cur_row_contain_zero = true;
        }
      }

      if (cur_row_contain_zero) {
        for (int j = 0; j < n; ++j) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (matrix[0][i] == 0) {
        for (int j = 1; j < m; ++j) {
          matrix[j][i] = 0;
        }
      }
    }

    if (first_row_contain_zero) {
      for (int i = 0; i < n; ++i) {
        matrix[0][i] = 0;
      }
    }
  }
};
// Runtime: 48 ms, faster than 62.94%
// Memory Usage: 11.3 MB, less than 100.00%