class Solution {
 public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<int>> matrix(n, vector<int>(m));

    for (auto index : indices) {
      for (int i = 0; i < m; ++i) {
        ++matrix[index[0]][i];
      }

      for (int i = 0; i < n; ++i) {
        ++matrix[i][index[1]];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans += (matrix[i][j] & 0x01);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 83.04%
// Memory Usage: 9.7 MB, less than 100.00%

class Solution {
 public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<int>> matrix(n, vector<int>(m));

    for (auto index : indices) {
      for (int i = 0; i < m; ++i) {
        ++matrix[index[0]][i];
      }

      for (int i = 0; i < n; ++i) {
        ++matrix[i][index[1]];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] % 2 != 0) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 83.04%
// Memory Usage: 9.6 MB, less than 100.00%