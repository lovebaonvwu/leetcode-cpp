class Solution {
 public:
  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));
    for (int j = 0; j <= n; ++j) {
      dp[0][j] = 0;
    }

    for (int i = 1; i <= target; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i][j - 1];

        int num = nums[j - 1];
        if (i - num >= 0 && dp[i - num][j - 1] != -1) {
          dp[i][j] = max(dp[i][j], dp[i - num][j - 1] + 1);
        }
      }
    }

    return dp[target][n];
  }
};
// 618ms
// 165.24MB