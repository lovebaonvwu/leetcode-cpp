class Solution {
 public:
  int minSteps(int n) {
    vector<int> dp(n + 1);

    for (int i = 2; i < n + 1; ++i) {
      dp[i] = i;

      for (int j = i / 2; j > 1; --j) {
        if (i % j == 0) {
          dp[i] = dp[j] + (i / j);
          break;
        }
      }
    }

    return dp[n];
  }
};
// Runtime: 4 ms, faster than 63.50%
// Memory Usage: 6.6 MB, less than 31.72%