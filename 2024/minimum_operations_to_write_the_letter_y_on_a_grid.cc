class Solution {
 public:
  int minimumOperationsToWriteY(vector<vector<int>>& grid) {
    int n = grid.size();

    int y[3] = {0};
    int x[3] = {0};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i < (n + 1) / 2 && (i == j || i == n - 1 - j)) {
          ++y[grid[i][j]];
        } else if (i >= (n + 1) / 2 && j == n / 2) {
          ++y[grid[i][j]];
        } else {
          ++x[grid[i][j]];
        }
      }
    }

    int ans = n * n;

    ans = min(ans, y[1] + y[2] + min(x[0] + x[2], x[0] + x[1]));
    ans = min(ans, y[0] + y[2] + min(x[1] + x[2], x[0] + x[1]));
    ans = min(ans, y[0] + y[1] + min(x[1] + x[2], x[0] + x[2]));

    return ans;
  }
};
// 45 ms
// 40.88 MB