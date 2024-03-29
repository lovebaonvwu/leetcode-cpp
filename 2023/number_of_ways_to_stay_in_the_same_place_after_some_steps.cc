class Solution {
 public:
  int numWays(int steps, int arrLen) {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(steps + 1, vector<int>(arrLen, -1));
    function<int(int, int)> dfs = [&](int steps, int i) -> int {
      if (steps == 0 && i == 0) {
        return 1;
      }

      if (steps == 0) {
        return 0;
      }

      if (dp[steps][i] != -1) {
        return dp[steps][i];
      }

      int cnt = 0;
      cnt = (cnt + dfs(steps - 1, i)) % mod;

      if (i > 0) {
        cnt = (cnt + dfs(steps - 1, i - 1)) % mod;
      }

      if (i < arrLen - 1) {
        cnt = (cnt + dfs(steps - 1, i + 1)) % mod;
      }

      return dp[steps][i] = cnt;
    };

    return dfs(steps, 0);
  }
};
// Memory Limit Exceeded

class Solution {
 public:
  int numWays(int steps, int arrLen) {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
    function<int(int, int)> dfs = [&](int steps, int i) -> int {
      if (steps == 0 && i == 0) {
        return 1;
      }

      if (steps == 0) {
        return 0;
      }

      if (i > steps) {
        return 0;
      }

      if (dp[steps][i] != -1) {
        return dp[steps][i];
      }

      int cnt = 0;
      cnt = (cnt + dfs(steps - 1, i)) % mod;

      if (i > 0) {
        cnt = (cnt + dfs(steps - 1, i - 1)) % mod;
      }

      if (i < arrLen - 1) {
        cnt = (cnt + dfs(steps - 1, i + 1)) % mod;
      }

      return dp[steps][i] = cnt;
    };

    return dfs(steps, 0);
  }
};
// 29ms
// 13.95MB

class Solution {
 public:
  int numWays(int steps, int arrLen) {
    int mod = 1e9 + 7;
    int len = min(steps + 1, arrLen);
    vector<vector<int>> dp(steps + 1, vector<int>(len));
    dp[0][0] = 1;
    for (int i = 1; i <= steps; ++i) {
      for (int j = len - 1; j >= 0; --j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        if (j < len - 1) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
        if (j > 0) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        }
      }
    }

    return dp[steps][0];
  }
};
// 44ms
// 13.29MB