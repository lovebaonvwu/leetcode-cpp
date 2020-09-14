class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int ans = 0;

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          bool special = true;

          for (int k = 0; k < n; ++k) {
            if (k != j && mat[i][k] == 1) {
              special = false;
              break;
            }
          }

          for (int k = 0; k < m; ++k) {
            if (k != i && mat[k][j] == 1) {
              special = false;
              break;
            }
          }

          if (special) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 100.00%
// Memory Usage: 13.1 MB, less than 33.33%

class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> row(m);
    vector<int> col(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          ++row[i];
          ++col[j];
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 100.00%
// Memory Usage: 13.2 MB, less than 33.33%