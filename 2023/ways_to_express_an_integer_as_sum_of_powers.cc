class Solution {
 public:
  int numberOfWays(int n, int x) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    int mod = 1e9 + 7;

    for (int i = 1; i <= n; ++i) {
      int ix = pow(i, x);
      if (ix > n) {
        break;
      }
      for (int j = n; j - ix >= 0; --j) {
        dp[j] = (dp[j] + dp[j - ix]) % mod;
      }
    }

    return dp[n];
  }
};
// 50ms
// 7.76mb