class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> rows(m);
    vector<int> cols(n);

    int ans = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++rows[i];
          ++cols[j];
          ++ans;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
          --ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 52.48%
// Memory Usage: 15.2 MB, less than 100.00%