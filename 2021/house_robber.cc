class Solution {
 public:
  int rob(vector<int>& nums) {
    if (!nums.size()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size(), -1);

    dp[nums.size() - 1] = nums[nums.size() - 1];
    dp[nums.size() - 2] = nums[nums.size() - 2];

    return dfs(nums, 0, dp);
  }

  int dfs(vector<int>& nums, int pos, vector<int>& dp) {
    if (dp[pos] > -1) {
      return max(dp[pos], pos + 1 < nums.size() ? dp[pos + 1] : 0);
    }

    dp[pos] = nums[pos] + dfs(nums, pos + 2, dp);

    return max(dp[pos], dfs(nums, pos + 1, dp));
  }
};  // 0ms

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (!nums.size()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size(), -1);

    dp[nums.size() - 1] = nums[nums.size() - 1];
    dp[nums.size() - 2] = nums[nums.size() - 2];

    return dfs(nums, 0, dp);
  }

  int dfs(vector<int>& nums, int pos, vector<int>& dp) {
    if (dp[pos] > -1) {
      return max(dp[pos], pos + 1 < nums.size() ? dp[pos + 1] : 0);
    }

    dp[pos] = nums[pos] + dfs(nums, pos + 2, dp);

    if (pos + 3 < nums.size()) {
      dp[pos + 1] = nums[pos + 1] + dfs(nums, pos + 3, dp);
    }

    return max(dp[pos], pos + 1 < nums.size() ? dp[pos + 1] : 0);
  }
};  // 0ms

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size(), 0);

    dp[nums.size() - 1] = nums[nums.size() - 1];
    dp[nums.size() - 2] = max(nums[nums.size() - 1], nums[nums.size() - 2]);

    for (int i = nums.size() - 3; i >= 0; --i) {
      dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }

    return max(dp[0], dp[1]);
  }
};  // 4ms