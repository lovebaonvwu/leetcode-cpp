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

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int dp[51][51][51]{0};
    memset(dp, -1, sizeof(dp));

    int mod = 1e9 + 7;

    int dirs[] = {0, 1, 0, -1, 0};

    function<int(int, int, int)> dfs = [&](int moves, int i, int j) -> int {
      if (i < 0 || i == m || j < 0 || j == n)
        return 1;
      if (moves == 0)
        return 0;

      if (dp[moves][i][j] != -1) {
        return dp[moves][i][j];
      }

      int res = 0;
      for (int k = 0; k < 4; ++k) {
        int y = i + dirs[k];
        int x = j + dirs[k + 1];

        res = (res + dfs(moves - 1, y, x)) % mod;
      }

      return dp[moves][i][j] = res;
    };

    return dfs(maxMove, startRow, startColumn);
  }
};
// 3ms
// 8.93MB