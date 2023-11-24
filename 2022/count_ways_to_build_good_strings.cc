class Solution {
 public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1);
    dp[0] = 1;
    long long ans = 0;
    int mod = 1e9 + 7;

    for (int i = 1; i <= high; ++i) {
      if (i >= zero) {
        dp[i] = (dp[i] + dp[i - zero]) % mod;
      }

      if (i >= one) {
        dp[i] = (dp[i] + dp[i - one]) % mod;
      }

      if (i >= low && i <= high) {
        ans = (ans + dp[i]) % mod;
      }
    }

    return ans;
  }
};
// Runtime 15 ms
// Memory 9.3 MB
// 2022.11.15 at 奥盛大厦