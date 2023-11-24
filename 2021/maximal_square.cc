class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    size_t m = matrix.size();
    size_t n = matrix[0].size();

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i && j && matrix[i][j] == '1') {
          matrix[i][j] = min(matrix[i - 1][j - 1],
                             min(matrix[i][j - 1], matrix[i - 1][j])) -
                         '0' + 1 + '0';
        }
        ans = max(ans, matrix[i][j] - '0');
      }
    }

    return ans * ans;
  }
};
// Runtime: 20 ms, faster than 81.74%
// Memory Usage: 10.5 MB, less than 92.59%

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    size_t m = matrix.size();
    size_t n = matrix[0].size();

    vector<vector<int>> tmp(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp[i][j] = matrix[i][j] - '0';
      }
    }

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i && j && tmp[i][j]) {
          tmp[i][j] +=
              min(tmp[i - 1][j - 1], min(tmp[i][j - 1], tmp[i - 1][j]));
        }
        ans = max(ans, tmp[i][j]);
      }
    }

    return ans * ans;
  }
};
// Runtime: 24 ms, faster than 42.25%
// Memory Usage: 11 MB, less than 62.96%