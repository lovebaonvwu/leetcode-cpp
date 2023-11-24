class Solution {
 public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = nums[0] == nums[1];

    if (n == 2) {
      return dp[1];
    }

    dp[2] = (nums[2] == nums[1] && nums[1] == nums[0]) ||
            (nums[2] == (nums[1] + 1) && nums[1] == (nums[0] + 1));

    for (int i = 3; i < n; ++i) {
      if (nums[i] == nums[i - 1]) {
        dp[i] |= dp[i - 2];
      }

      if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
        dp[i] |= dp[i - 3];
      }

      if ((nums[i] == nums[i - 1] + 1) && (nums[i - 1] == nums[i - 2] + 1)) {
        dp[i] |= dp[i - 3];
      }
    }

    return dp[n - 1];
  }
};
// Runtime: 246 ms, faster than 55.56%
// Memory Usage: 87.6 MB, less than 22.22%
// 2022.8.10 at 奥盛大厦