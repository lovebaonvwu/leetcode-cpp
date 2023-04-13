class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<int> dp(n, 1);

    int ans = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] == nums[j] * nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      ans = max(ans, dp[i]);
    }

    return ans == 1 ? -1 : ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int dp[100001] = {0};
    dp[nums[0]] = 1;

    int ans = 1;
    for (int i = 1; i < n; ++i) {
      dp[nums[i]] = 1;
      int prev = sqrt(nums[i]);
      if (prev * prev != nums[i]) {
        continue;
      }

      if (dp[prev]) {
        dp[nums[i]] = dp[prev] + 1;
      }

      ans = max(ans, dp[nums[i]]);
    }

    return ans == 1 ? -1 : ans;
  }
};
// Runtime 195 ms
// Memory 83 MB