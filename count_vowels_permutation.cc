class Solution {
 public:
  int countVowelPermutation(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(5));

    int mod = 1e9 + 7;

    for (int i = 0; i < 5; ++i) {
      dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
      dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod;
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
      dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
      dp[i][3] = dp[i - 1][2];
      dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
    }

    int ans = 0;

    for (auto cnt : dp[n]) {
      ans = (ans + cnt) % mod;
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 44.84%
// Memory Usage: 23.8 MB, less than 30.28%
// 2021.7.4 at 奥盛大厦