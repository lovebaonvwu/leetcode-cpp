class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return {};
    }

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> ans;

    bool goTopRight = true;

    for (int i = 0, j = 0; ans.size() < m * n;) {
      ans.push_back(matrix[i][j]);

      if (goTopRight) {
        if (i - 1 < 0 || j + 1 == n) {
          goTopRight = !goTopRight;

          if (j + 1 < n) {
            j += 1;
          } else if (i + 1 < m) {
            i += 1;
          }
        } else {
          i -= 1;
          j += 1;
        }

      } else {
        if (i + 1 == m || j - 1 < 0) {
          goTopRight = !goTopRight;

          if (i + 1 < m) {
            i += 1;
          } else if (j + 1 < n) {
            j += 1;
          }
        } else {
          i += 1;
          j -= 1;
        }
      }
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 84.30%
// Memory Usage: 18.6 MB, less than 79.11%

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();

    if (!m) {
      return {};
    }

    int n = matrix[0].size();

    vector<vector<int>> tmp(m + n - 1);

    for (int k = 0; k < m + n - 1; ++k) {
      int i = max(0, k - n + 1);
      int j = min(k, n - 1);

      for (; i < m && j >= 0; ++i, --j) {
        tmp[k].push_back(matrix[i][j]);
      }
    }

    vector<int> ans;

    for (int i = 0; i < tmp.size(); ++i) {
      if (i % 2 == 0) {
        ans.insert(ans.end(), tmp[i].rbegin(), tmp[i].rend());
      } else {
        ans.insert(ans.end(), tmp[i].begin(), tmp[i].end());
      }
    }

    return ans;
  }
};
// Runtime: 88 ms, faster than 28.50%
// Memory Usage: 22.9 MB, less than 20.41%