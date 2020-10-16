class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();

    if (!m) {
      return false;
    }

    int n = matrix[0].size();

    if (!n) {
      return false;
    }

    for (int i = 0, j = n - 1; i < m && j >= 0;) {
      if (matrix[i][j] < target) {
        ++i;
      } else if (matrix[i][j] > target) {
        --j;
      } else {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 84 ms, faster than 97.41%
// Memory Usage: 11 MB, less than 97.09%