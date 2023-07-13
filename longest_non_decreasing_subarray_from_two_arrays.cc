class Solution {
 public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = dp[1][0] = 1;

    int ans = 1;
    for (int j = 1; j < n; ++j) {
      if (nums1[j] < nums1[j - 1] && nums1[j] < nums2[j - 1]) {
        dp[0][j] = 1;
      } else if (nums1[j] < nums1[j - 1]) {
        dp[0][j] = dp[1][j - 1] + 1;
      } else if (nums1[j] < nums2[j - 1]) {
        dp[0][j] = dp[0][j - 1] + 1;
      } else {
        dp[0][j] = max(dp[0][j - 1], dp[1][j - 1]) + 1;
      }

      if (nums2[j] < nums1[j - 1] && nums2[j] < nums2[j - 1]) {
        dp[1][j] = 1;
      } else if (nums2[j] < nums1[j - 1]) {
        dp[1][j] = dp[1][j - 1] + 1;
      } else if (nums2[j] < nums2[j - 1]) {
        dp[1][j] = dp[0][j - 1] + 1;
      } else {
        dp[1][j] = max(dp[0][j - 1], dp[1][j - 1]) + 1;
      }

      ans = max(ans, max(dp[0][j], dp[1][j]));
    }

    return ans;
  }
};
// Runtime 286 ms
// Memory 166.3 MB