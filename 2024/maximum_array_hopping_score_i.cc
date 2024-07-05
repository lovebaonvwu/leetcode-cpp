class Solution {
 public:
  int maxScore(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] = max(dp[i], (i - j) * nums[i] + dp[j]);
      }
    }

    return dp[n - 1];
  }
};
// 117 ms
// 30.38 MB