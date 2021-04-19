class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1);

    dp[0] = 1;

    for (int i = 1; i <= target; ++i) {
      for (auto n : nums) {
        if (i - n >= 0) {
          dp[i] += dp[i - n];
        }
      }
    }

    return dp[target];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.8 MB, less than 48.90%