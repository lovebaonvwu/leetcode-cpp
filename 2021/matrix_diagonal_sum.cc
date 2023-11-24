class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;

    int n = mat.size();
    for (int i = 0; i < n; ++i) {
      sum += mat[i][i];

      if (i != n - 1 - i) {
        sum += mat[i][n - 1 - i];
      }
    }

    return sum;
  }
};
// Runtime: 32 ms, faster than 50.00%
// Memory Usage: 11.4 MB, less than 83.33%