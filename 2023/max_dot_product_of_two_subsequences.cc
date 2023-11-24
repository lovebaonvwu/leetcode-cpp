class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i == m || j == n) {
        return INT_MIN;
      }

      if (dp[i][j] != INT_MIN) {
        return dp[i][j];
      }

      int ans = INT_MIN;

      ans = max(ans, nums1[i] * nums2[j] + max(dfs(i + 1, j + 1), 0));
      ans = max(ans, dfs(i + 1, j));
      ans = max(ans, dfs(i, j + 1));

      return dp[i][j] = ans;
    };

    return dfs(0, 0);
  }
};
// 55ms
// 13.64MB