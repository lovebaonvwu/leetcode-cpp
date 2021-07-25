class Solution {
 public:
  int findIntegers(int n) {
    int dp[32] = {0};
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < 32; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    int k = 30, prev = 0, ans = 0;

    while (k >= 0) {
      if (n & (1 << k)) {
        ans += dp[k];
        if (prev == 1) {
          return ans;
        }

        prev = 1;
      } else {
        prev = 0;
      }

      --k;
    }

    return ans + 1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 90.24%
// 2021.7.25 at 奥盛大厦