class Solution {
 public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
      return {};
    }

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = original[i * n + j];
      }
    }

    return ans;
  }
};
// Runtime: 108 ms, faster than 93.48%
// Memory Usage: 85.4 MB, less than 66.70%
// 2021.10.05 at 茗筑美嘉