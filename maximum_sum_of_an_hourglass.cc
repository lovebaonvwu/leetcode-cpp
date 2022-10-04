class Solution {
 public:
  int maxSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        int sum = grid[i][j];
        for (int k = -1; k <= 1; ++k) {
          sum += grid[i - 1][j + k];
          sum += grid[i + 1][j + k];
        }

        ans = max(ans, sum);
      }
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 53.99%
// Memory Usage: 13.1 MB, less than 89.47%
// 2022.10.4 at 茗筑美嘉