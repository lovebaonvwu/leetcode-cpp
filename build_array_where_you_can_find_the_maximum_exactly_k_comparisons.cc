class Solution {
 public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

    int mod = 1e9 + 7;
    function<int(int, int, int)> dfs = [&](int i, int curmax,
                                           int remain) -> int {
      if (i == n && remain == 0) {
        return 1;
      }

      if (i == n) {
        return 0;
      }

      if (remain < 0) {
        return 0;
      }

      if (dp[i][curmax][remain] != -1) {
        return dp[i][curmax][remain];
      }

      int ans = 0;
      for (int j = 1; j <= curmax; ++j) {
        ans = (ans + dfs(i + 1, curmax, remain)) % mod;
      }

      for (int j = curmax + 1; j <= m; ++j) {
        ans = (ans + dfs(i + 1, j, remain - 1)) % mod;
      }

      return dp[i][curmax][remain] = ans;
    };

    return dfs(0, 0, k);
  }
};
// 363ms
// 10.40MB