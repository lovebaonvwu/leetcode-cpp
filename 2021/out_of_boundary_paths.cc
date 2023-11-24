class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<int>> dp(m, vector<int>(n));

    vector<int> dirs{0, -1, 0, 1, 0};

    int mod = 1e9 + 7;

    for (int k = 0; k < maxMove; ++k) {
      vector<vector<int>> tmp(m, vector<int>(n));

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          for (int x = 0; x < 4; ++x) {
            auto dx = i + dirs[x];
            auto dy = j + dirs[x + 1];

            if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
              tmp[i][j] += 1;
            } else {
              tmp[i][j] = (tmp[i][j] + dp[dx][dy]) % mod;
            }
          }
        }
      }

      dp = tmp;
    }

    return dp[startRow][startColumn];
  }
};
// Runtime: 32 ms, faster than 22.48%
// Memory Usage: 9.5 MB, less than 39.26%