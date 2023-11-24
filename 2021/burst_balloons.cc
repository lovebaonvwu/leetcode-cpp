class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int len = 1; len <= n; ++len) {
      for (int i = 1; i <= n - len + 1; ++i) {
        int j = i + len - 1;

        for (int k = i; k <= j; ++k) {
          dp[i][j] =
              max(dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] +
                                dp[k + 1][j]);
        }
      }
    }

    return dp[1][n];
  }
};
// Runtime: 36 ms, faster than 61.56%
// Memory Usage: 9.1 MB, less than 26.40%