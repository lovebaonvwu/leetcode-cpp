class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 1));
    int odd_idx = -1;
    int even_idx = -1;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 == 0) {
        if (odd_idx >= 0) {
          dp[i][1] = dp[odd_idx][1] + 1;
        }

        if (even_idx >= 0) {
          dp[i][0] = dp[even_idx][0] + 1;
        }

        even_idx = i;
      } else {
        if (odd_idx >= 0) {
          dp[i][0] = dp[odd_idx][0] + 1;
        }

        if (even_idx >= 0) {
          dp[i][1] = dp[even_idx][1] + 1;
        }

        odd_idx = i;
      }

      ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    return ans;
  }
};
// 216 ms
// 142.45 MB