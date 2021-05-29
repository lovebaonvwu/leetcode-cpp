class Solution {
  vector<int> diag1;
  vector<int> diag2;
  vector<int> cols;
  int N;
  int ans;

 public:
  int totalNQueens(int n) {
    N = n;

    cols = vector<int>(n);
    diag1 = vector<int>(2 * n - 1);
    diag2 = vector<int>(2 * n - 1);

    dfs(0);

    return ans;
  }

  void dfs(int m) {
    if (m == N) {
      ++ans;
      return;
    }

    for (int i = 0; i < N; ++i) {
      if (canPlace(m, i)) {
        place(m, i, true);
        dfs(m + 1);
        place(m, i, false);
      }
    }
  }

  bool canPlace(int m, int n) {
    return !cols[n] && !diag1[m + n] && !diag2[(N - 1) - (m - n)];
  }

  void place(int m, int n, bool b) {
    cols[n] = b;
    diag1[m + n] = b;
    diag2[N - 1 - (m - n)] = b;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 64.80%