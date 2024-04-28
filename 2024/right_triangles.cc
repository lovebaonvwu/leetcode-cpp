class Solution {
 public:
  long long numberOfRightTriangles(vector<vector<int>>& grid) {
    long long ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    vector<int> row(m);
    vector<int> col(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++row[i];
          ++col[j];
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ans += 1LL * ((row[i] - 1) * (col[j] - 1));
        }
      }
    }

    return ans;
  }
};
// 248 ms
// 113.12 MB