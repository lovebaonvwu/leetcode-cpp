class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();

    for (int i = 0; i < m; ++i) {
      if (A[i][0] == 0) {
        for (int j = 0; j < n; ++j) {
          A[i][j] = A[i][j] ? 0 : 1;
        }
      }
    }

    for (int j = 1; j < n; ++j) {
      int cnt = 0;

      for (int i = 0; i < m; ++i) {
        if (A[i][j] == 1) {
          ++cnt;
        }
      }

      if (cnt < m - cnt) {
        for (int i = 0; i < m; ++i) {
          A[i][j] = A[i][j] ? 0 : 1;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        sum += A[i][j] << (n - 1 - j);
      }

      ans += sum;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 77.12%
// Memory Usage: 8 MB, less than 94.34%

class Solution {
 public:
  int matrixScore(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();

    int ans = (1 << (n - 1)) * m;

    for (int j = 1; j < n; ++j) {
      int cnt = 0;

      for (int i = 0; i < m; ++i) {
        cnt += A[i][j] == A[i][0];
      }

      ans += max(cnt, m - cnt) * (1 << (n - 1 - j));
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 77.12%
// Memory Usage: 8.1 MB, less than 94.34%