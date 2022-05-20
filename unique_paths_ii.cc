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

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    dp[0][1] =
        1;  // start point dp[1][0] is also ok. We need to init dp[1][1] = 1;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (obstacleGrid[i - 1][j - 1] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime: 8 ms, faster than 22.56%
// Memory Usage: 7.9 MB, less than 41.40%
// 2022.5.20 at 奥盛大厦