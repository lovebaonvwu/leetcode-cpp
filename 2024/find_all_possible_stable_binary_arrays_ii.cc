class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<long long>>> dp(
        zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));
    vector<vector<long long>> presum0(zero + 1, vector<long long>(one + 1));
    vector<vector<long long>> presum1(zero + 1, vector<long long>(one + 1));
    for (int i = 0; i <= zero; ++i) {
      if (i <= limit)
        dp[i][0][0] = 1;
      presum0[i][0] = dp[i][0][0];
    }

    for (int j = 0; j <= one; ++j) {
      if (j <= limit)
        dp[0][j][1] = 1;
      presum1[0][j] = dp[0][j][1];
    }

    int mod = 1e9 + 7;

    for (int i = 1; i <= zero; ++i) {
      for (int j = 1; j <= one; ++j) {
        dp[i][j][1] = presum0[i][j - 1] % mod;
        dp[i][j][0] = presum1[i - 1][j] % mod;
        if (j - limit - 1 >= 0)
          dp[i][j][1] = (dp[i][j][1] - presum0[i][j - limit - 1] + mod) % mod;
        if (i - limit - 1 >= 0)
          dp[i][j][0] = (dp[i][j][0] - presum1[i - limit - 1][j] + mod) % mod;

        presum1[i][j] = (dp[i][j][1] + presum1[i - 1][j]) % mod;
        presum0[i][j] = (dp[i][j][0] + presum0[i][j - 1]) % mod;
      }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % mod;
  }
};
// 1424 ms
// 607.84 MB