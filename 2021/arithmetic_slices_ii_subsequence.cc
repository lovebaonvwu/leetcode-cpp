class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();

    vector<unordered_map<long, int>> dp(n);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long diff = (long)nums[i] - nums[j];

        ans += dp[j][diff];
        dp[i][diff] += dp[j][diff] + 1;
      }
    }

    return ans;
  }
};
// Runtime: 1904 ms, faster than 5.07%
// Memory Usage: 285.2 MB, less than 9.02%
// 2021.9.10 at 奥盛大厦