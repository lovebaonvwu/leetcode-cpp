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

class Solution {
 public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int dp1 = 1, dp2 = 1;
    int n = nums1.size();
    int ans = 1;

    for (int j = 1; j < n; ++j) {
      int t11 = nums1[j] >= nums1[j - 1] ? dp1 + 1 : 1;
      int t12 = nums1[j] >= nums2[j - 1] ? dp2 + 1 : 1;
      int t21 = nums2[j] >= nums1[j - 1] ? dp1 + 1 : 1;
      int t22 = nums2[j] >= nums2[j - 1] ? dp2 + 1 : 1;
      dp1 = max(t11, t12);
      dp2 = max(t21, t22);
      ans = max(ans, max(dp1, dp2));
    }

    return ans;
  }
};
// Runtime 235 ms
// Memory 160.1 MB