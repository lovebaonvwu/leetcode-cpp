class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m - 1; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        if (matrix[i][j] != matrix[i + 1][j + 1]) {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 76.07%
// Memory Usage: 9.7 MB, less than 71.43%