class Solution {
 public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    for (int j = 0; j < n; ++j) {
      dp[0][j] = grid[0][j];
    }

    for (int i = 1; i < m; ++i) {
      for (int k = 0; k < n; ++k) {
        int node = grid[i][k];
        for (int j = 0; j < n; ++j) {
          int prev = moveCost[grid[i - 1][j]][k];
          dp[i][k] = min(dp[i][k], dp[i - 1][j] + node + prev);
        }
      }
    }

    return *min_element(dp.back().begin(), dp.back().end());
  }
};
// Runtime: 805 ms, faster than 5.00%
// Memory Usage: 80.4 MB, less than 45.10%
// 2022.7.5 at 奥盛大厦