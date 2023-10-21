class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1);

    int ans = INT_MIN;
    for (int j = 1; j <= n; ++j) {
      dp[j] = nums[j - 1];
      for (int i = max(0, j - k); i < j; ++i) {
        dp[j] = max(dp[j], nums[j - 1] + dp[i]);
      }

      ans = max(ans, dp[j]);
    }

    return ans;
  }
};
// Time Limit Exceeded