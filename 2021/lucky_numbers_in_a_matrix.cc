class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> ans;

    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> row;
    unordered_set<int> col;

    for (int i = 0; i < m; ++i) {
      row.insert(*min_element(matrix[i].begin(), matrix[i].end()));
    }

    for (int i = 0; i < n; ++i) {
      int mx = 0;
      for (int j = 0; j < m; ++j) {
        mx = max(mx, matrix[j][i]);
      }

      col.insert(mx);
    }

    for (auto n : row) {
      if (col.count(n)) {
        ans.push_back(n);
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 58.33%
// Memory Usage: 10.2 MB, less than 100.00%

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> ans;

    for (int i = 0; i < matrix.size(); ++i) {
      int row_min = matrix[i][0], min_col = 0;

      for (int j = 1; j < matrix[0].size(); ++j) {
        if (matrix[i][j] < row_min) {
          row_min = matrix[i][j];
          min_col = j;
        }
      }

      bool lucky = true;

      for (int j = 0; j < matrix.size(); ++j) {
        if (matrix[j][min_col] > row_min) {
          lucky = false;
          break;
        }
      }

      if (lucky) {
        ans.push_back(row_min);
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 91.67%
// Memory Usage: 9.7 MB, less than 100.00%

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row_min(m, INT_MAX);
    vector<int> col_max(n, INT_MIN);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        row_min[i] = min(row_min[i], matrix[i][j]);
        col_max[j] = max(col_max[j], matrix[i][j]);
      }
    }

    vector<int> ans;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (row_min[i] == col_max[j]) {
          ans.push_back(row_min[i]);
        }
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 58.33%
// Memory Usage: 9.4 MB, less than 100.00%