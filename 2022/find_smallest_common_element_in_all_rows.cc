class Solution {
 public:
  int smallestCommonElement(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int k = 0; k < n; ++k) {
      int target = mat[0][k];
      int cnt = 1;
      for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (mat[i][j] == target) {
            ++cnt;
            break;
          }
        }
      }

      if (cnt == m) {
        return mat[0][k];
      }
    }

    return -1;
  }
};
// Runtime 1000 ms
// Memory 24.2 MB
// 2022.11.22 at 茗筑美嘉

class Solution {
 public:
  int smallestCommonElement(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int k = 0; k < n; ++k) {
      int target = mat[0][k];
      int cnt = 1;
      for (int i = 1; i < m; ++i) {
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
          int md = (lo + hi) / 2;
          if (mat[i][md] == target) {
            ++cnt;
            break;
          } else if (mat[i][md] < target) {
            lo = md + 1;
          } else {
            hi = md - 1;
          }
        }
      }

      if (cnt == m) {
        return mat[0][k];
      }
    }

    return -1;
  }
};
// Runtime 267 ms
// Memory 24 MB
// 2022.11.22 at 茗筑美嘉