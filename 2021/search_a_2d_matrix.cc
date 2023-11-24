class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }

    int lo = 0;
    int hi = matrix.size() - 1;

    int row = -1;
    int col = matrix[0].size() - 1;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      if (matrix[md][0] <= target && matrix[md][col] >= target) {
        row = md;
        break;
      } else if (matrix[md][0] > target) {
        hi = md - 1;
      } else if (matrix[md][col] < target) {
        lo = md + 1;
      }
    }

    if (row < 0) {
      return false;
    }

    lo = 0;
    hi = col;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      if (matrix[row][md] == target) {
        return true;
      } else if (matrix[row][md] < target) {
        lo = md + 1;
      } else {
        hi = md - 1;
      }
    }

    return false;
  }
};
// Runtime: 12 ms, faster than 50.69%
// Memory Usage: 9.7 MB, less than 100.00%

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    int lo = 0;
    int hi = rows * cols - 1;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      int val = matrix[md / cols][md % cols];
      if (val == target) {
        return true;
      } else if (val > target) {
        hi = md - 1;
      } else {
        lo = md + 1;
      }
    }

    return false;
  }
};
// Runtime: 12 ms, faster than 50.69%
// Memory Usage: 9.6 MB, less than 100.00%