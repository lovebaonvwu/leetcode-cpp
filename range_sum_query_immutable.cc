class NumArray {
  vector<int> dp;

 public:
  NumArray(vector<int>& nums) {
    if (!nums.empty()) {
      dp.push_back(nums[0]);

      for (int i = 1; i < nums.size(); ++i) {
        dp.push_back(dp[i - 1] + nums[i]);
      }
    }
  }

  int sumRange(int i, int j) { return i == 0 ? dp[j] : dp[j] - dp[i - 1]; }
};
// Runtime: 36 ms, faster than 43.88%
// Memory Usage: 17.3 MB, less than 72.41%