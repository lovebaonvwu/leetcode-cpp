class Solution {
 public:
  int maximumLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int c = 0; c <= k; ++c)
      dp[0][c] = 1;
    for (int i = 0; i < n; ++i)
      dp[i][0] = 1;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int c = 0; c <= k; ++c) {
        for (int j = 0; j < i; ++j) {
          if (nums[j] == nums[i]) {
            dp[i][c] = max(dp[i][c], dp[j][c] + 1);
          } else if (c > 0) {
            dp[i][c] = max(dp[i][c], dp[j][c - 1] + 1);
          }
        }
        ans = max(ans, dp[i][c]);
      }
    }

    return ans;
  }
};
// 266 ms
// 23.31 MB