class Solution {
 public:
  int stringCount(int n) {
    if (n < 4) {
      return 0;
    }

    int mod = 1e9 + 7;

    vector<vector<int>> dp(n, vector<int>(16, -1));

    function<int(int, int)> dfs = [&](int i, int mask) -> int {
      if (i == n) {
        return mask == 15;
      }

      if (dp[i][mask] != -1) {
        return dp[i][mask];
      }

      int cnt = 0;
      for (int k = 0; k < 26; ++k) {
        if ((k + 'a' == 'l') && !(mask & 0b1000)) {
          cnt = (cnt + dfs(i + 1, mask | 0b1000)) % mod;
        } else if ((k + 'a' == 'e') && !(mask & 0b0100)) {
          cnt = (cnt + dfs(i + 1, mask | 0b0100)) % mod;
        } else if ((k + 'a' == 'e') && !(mask & 0b0010)) {
          cnt = (cnt + dfs(i + 1, mask | 0b0010)) % mod;
        } else if ((k + 'a' == 't') && !(mask & 0b0001)) {
          cnt = (cnt + dfs(i + 1, mask | 0b0001)) % mod;
        } else {
          cnt = (cnt + dfs(i + 1, mask)) % mod;
        }
      }

      return dp[i][mask] = cnt;
    };

    return dfs(0, 0);
  }
};
// 1255ms
// 64.77MB