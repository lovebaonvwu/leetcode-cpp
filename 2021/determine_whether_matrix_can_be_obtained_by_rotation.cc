class Solution {
 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    if (mat == target) {
      return true;
    }

    int n = mat.size();

    for (int k = 3; k > 0; --k) {
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          swap(mat[i][j], mat[j][i]);
        }
      }

      for (int i = 0; i < n; ++i) {
        reverse(mat[i].begin(), mat[i].end());
      }

      if (mat == target) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 82.91%
// Memory Usage: 11.2 MB, less than 74.11%
// 2021.12.24 at 奥盛大厦

class Solution {
 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    vector<bool> c(4, true);

    int n = mat.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] != target[i][j]) {
          c[0] = false;
        }

        if (mat[n - j - 1][i] != target[i][j]) {
          c[1] = false;
        }

        if (mat[n - i - 1][n - j - 1] != target[i][j]) {
          c[2] = false;
        }

        if (mat[j][n - i - 1] != target[i][j]) {
          c[3] = false;
        }
      }
    }

    return any_of(c.begin(), c.end(), [](bool b) { return b == true; });
  }
};
// Runtime: 4 ms, faster than 82.91%
// Memory Usage: 11.3 MB, less than 37.12%