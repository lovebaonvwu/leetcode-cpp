class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    queue<vector<int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          q.push({i, j});
        } else {
          matrix[i][j] = INT_MAX;
        }
      }
    }

    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
      auto cell = q.front();
      q.pop();

      for (auto d : dir) {
        int i = cell[0] + d[0];
        int j = cell[1] + d[1];

        if (i < 0 || j < 0 || i == m || j == n ||
            matrix[i][j] <= matrix[cell[0]][cell[1]]) {
          continue;
        }

        matrix[i][j] = matrix[cell[0]][cell[1]] + 1;
        q.push({i, j});
      }
    }

    return matrix;
  }
};
// Runtime: 840 ms, faster than 5.12%
// Memory Usage: 124.9 MB, less than 5.06%

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int max_dis = m + n;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] != 0) {
          int left = j > 0 ? matrix[i][j - 1] : max_dis;
          int up = i > 0 ? matrix[i - 1][j] : max_dis;

          matrix[i][j] = min(left, up) + 1;
        }
      }
    }

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int right = j < n - 1 ? matrix[i][j + 1] : max_dis;
        int bottom = i < m - 1 ? matrix[i + 1][j] : max_dis;

        matrix[i][j] = min(matrix[i][j], min(right, bottom) + 1);
      }
    }

    return matrix;
  }
};
// Runtime: 108 ms, faster than 96.38%
// Memory Usage: 26.4 MB, less than 94.69%