class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));

    for (int i = 0, sum = 0; i < m; ++i) {
      sum += grid[i][0];
      dp[i][0][sum % k] = 1;
    }

    for (int j = 0, sum = 0; j < n; ++j) {
      sum += grid[0][j];
      dp[0][j][sum % k] = 1;
    }

    int mod = 1e9 + 7;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        int num = grid[i][j];
        for (int q = 0; q < k; ++q) {
          int cur = (dp[i - 1][j][q] + dp[i][j - 1][q]) % mod;
          dp[i][j][(num + q) % k] = (dp[i][j][(num + q) % k] + cur) % mod;
        }
      }
    }

    return dp[m - 1][n - 1][0];
  }
};
// Runtime: 905 ms, faster than 64.76%
// Memory Usage: 127.5 MB, less than 82.01%
// 2022.11.2 at 奥盛大厦

class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));

    for (int i = 0, sum = 0; i < m; ++i) {
      sum += grid[i][0];
      dp[i][0][sum % k] = 1;
    }

    for (int j = 0, sum = 0; j < n; ++j) {
      sum += grid[0][j];
      dp[0][j][sum % k] = 1;
    }

    int mod = 1e9 + 7;
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        int num = grid[i][j];
        for (int q = 0; q < k; ++q) {
          long long cur = dp[i - 1][j][q] + dp[i][j - 1][q];
          dp[i][j][(num + q) % k] = (dp[i][j][(num + q) % k] + cur) % mod;
        }
      }
    }

    return dp[m - 1][n - 1][0];
  }
};
// Runtime: 440 ms, faster than 94.01%
// Memory Usage: 127.5 MB, less than 82.01%
// 2022.11.2 at 奥盛大厦