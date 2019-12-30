class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) {
      return 0;
    }

    int n = obstacleGrid[0].size();
    if (n == 0) {
      return 0;
    }

    vector<long> prev(n);
    vector<long> cur(n);

    prev[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < n; ++i) {
      prev[i] = prev[i - 1] == 0 || obstacleGrid[0][i] == 1 ? 0 : 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) {
          cur[j] = 0;
        } else {
          if (j == 0) {
            cur[j] = prev[j];
          } else {
            cur[j] = cur[j - 1] + prev[j];
          }
        }
      }

      swap(prev, cur);
    }

    return (int)prev[n - 1];
  }
};
// Runtime: 4 ms, faster than 75.27%
// Memory Usage: 9 MB, less than 100.00%