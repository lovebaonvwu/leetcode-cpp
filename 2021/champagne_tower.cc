class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(101, vector<double>(101));

    dp[0][0] = poured;

    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[i][j] >= 1) {
          dp[i + 1][j] += (dp[i][j] - 1) / 2.0;
          dp[i + 1][j + 1] += (dp[i][j] - 1) / 2.0;
          dp[i][j] = 1;
        }
      }
    }

    return dp[query_row][query_glass];
  }
};
// Runtime: 36 ms, faster than 15.32%
// Memory Usage: 43.4 MB, less than 18.47%

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(101);

    dp[0] = poured;

    for (int i = 1; i <= query_row; ++i)
      for (int j = i - 1; j >= 0; --j)
        dp[j + 1] += dp[j] = max(0.0, (dp[j] - 1) / 2);

    return min(dp[query_glass], 1.0);
  }
};
// Runtime: 4 ms, faster than 94.59%
// Memory Usage: 6.8 MB, less than 18.47%

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(101);

    dp[0] = poured;

    for (int i = 0; i < query_row; ++i)
      for (int j = i; j >= 0; --j)
        dp[j + 1] += dp[j] = max(0.0, (dp[j] - 1) / 2);

    return min(dp[query_glass], 1.0);
  }
};
// Runtime: 4 ms, faster than 94.59%
// Memory Usage: 6.8 MB, less than 18.47%