class Solution {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    constexpr int mod = 12345;

    vector<vector<int>> topleft(m, vector<int>(n));
    vector<vector<int>> bottomright(m, vector<int>(n));
    vector<vector<int>> ans(m, vector<int>(n));

    long long p = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        topleft[i][j] = p;
        p *= grid[i][j];
        p %= mod;
      }
    }

    p = 1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        bottomright[i][j] = p;
        p *= grid[i][j];
        p %= mod;
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = topleft[i][j] * bottomright[i][j] % mod;
      }
    }

    return ans;
  }
};
// 270ms
// 159.89MB