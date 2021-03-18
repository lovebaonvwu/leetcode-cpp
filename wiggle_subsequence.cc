class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    vector<int> diff;

    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] != 0) {
        diff.push_back(nums[i] - nums[i - 1]);
      }
    }

    if (diff.empty()) {
      return 1;
    }

    vector<int> dp(diff.size(), 1);

    for (int i = 1; i < diff.size(); ++i) {
      if (diff[i] > 0 && diff[i - 1] < 0) {
        dp[i] = dp[i - 1] + 1;
      } else if (diff[i] < 0 && diff[i - 1] > 0) {
        dp[i] = dp[i - 1] + 1;
      } else {
        dp[i] = dp[i - 1];
      }
    }

    return dp.back() + 1;
  }
};
// Runtime: 4 ms, faster than 57.03%
// Memory Usage: 7.4 MB, less than 39.52%