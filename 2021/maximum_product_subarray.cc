class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<pair<int, int>> dp(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      dp[i] = {nums[i], nums[i]};
    }

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        dp[i].first = max(nums[i], dp[i - 1].first * nums[i]);
        dp[i].second = min(nums[i], dp[i - 1].second * nums[i]);
      } else {
        dp[i].first = max(nums[i], dp[i - 1].second * nums[i]);
        dp[i].second = min(nums[i], dp[i - 1].first * nums[i]);
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i < dp.size(); ++i) {
      ans = max(ans, dp[i].first);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 89.98%
// Memory Usage: 9.3 MB, less than 40.00%

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<pair<int, int>> dp(nums.size());

    dp[0] = {nums[0], nums[0]};

    int ans = dp[0].first;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        dp[i].first = max(nums[i], dp[i - 1].first * nums[i]);
        dp[i].second = min(nums[i], dp[i - 1].second * nums[i]);
      } else {
        dp[i].first = max(nums[i], dp[i - 1].second * nums[i]);
        dp[i].second = min(nums[i], dp[i - 1].first * nums[i]);
      }

      ans = max(ans, dp[i].first);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 10.77%
// Memory Usage: 9.4 MB, less than 15.00%