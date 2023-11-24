class Solution {
 public:
  int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(1001, 1));

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      int a = nums[i];
      for (int j = 0; j < i; ++j) {
        int b = nums[j];
        int c = (a - b) + 500;
        dp[i][c] = dp[j][c] + 1;
      }

      ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }

    return ans;
  }
};
// Runtime 490 ms
// Memory 141.6 MB
// 2022.11.9 at 奥盛大厦