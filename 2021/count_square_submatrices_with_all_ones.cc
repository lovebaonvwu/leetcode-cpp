class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i && j && matrix[i][j]) {
          matrix[i][j] += min(matrix[i - 1][j - 1],
                              min(matrix[i - 1][j], matrix[i][j - 1]));
        }

        ans += matrix[i][j];
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 96.19%
// Memory Usage: 16 MB, less than 100.00%

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();

    size_t s = max(m, n);

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < s; ++k) {
          int cnt = 0;

          for (int p = 0; p <= k && i + p < m; ++p) {
            for (int q = 0; q <= k && j + q < n; ++q) {
              if (matrix[i + p][j + q] == 1) {
                ++cnt;
              }
            }
          }

          if (cnt == (k + 1) * (k + 1)) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded