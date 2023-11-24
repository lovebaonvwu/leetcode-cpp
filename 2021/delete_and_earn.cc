class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    int dp[10001] = {0};

    for (auto n : nums) {
      dp[n] += n;
    }

    for (int i = 2; i < 10001; ++i) {
      dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
    }

    return dp[10000];
  }
};
// Runtime: 4 ms, faster than 96.16%
// Memory Usage: 9.1 MB, less than 87.70%