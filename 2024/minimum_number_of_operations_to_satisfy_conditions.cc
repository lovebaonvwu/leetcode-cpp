class Solution {
  int m;
  int n;
  int cnt[1001][10] = {};
  int cached[1001][10] = {};

  int dfs(int i, int prev, int n) {
    if (i == n)
      return 0;
    if (cached[i][prev] == 0) {
      for (int k = 0; k < 10; ++k) {
        if (i == 0 || k != prev) {
          cached[i][prev] = max(cached[i][prev], cnt[i][k] + dfs(i + 1, k, n));
        }
      }
    }

    return cached[i][prev];
  }

 public:
  int minimumOperations(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ++cnt[j][grid[i][j]];

    return m * n - dfs(0, 0, n);
  }
};
// 230 ms
// 114.52 MB