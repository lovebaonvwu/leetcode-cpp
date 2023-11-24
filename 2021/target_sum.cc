class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < S) {
      return 0;
    }

    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * sum + 1, 0));

    dp[0][sum] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; ++j) {
        if (dp[i][j]) {
          dp[i + 1][j - nums[i]] += dp[i][j];
          dp[i + 1][j + nums[i]] += dp[i][j];
        }
      }
    }

    return dp.back()[sum + S];
  }
};
// Runtime: 20 ms, faster than 77.45%
// Memory Usage: 21.7 MB, less than 30.77%

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum < S) {
      return 0;
    }

    vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));

    dp[0][sum + nums[0]] += 1;
    dp[0][sum - nums[0]] += 1;

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; ++j) {
        if (dp[i - 1][j]) {
          dp[i][j - nums[i]] += dp[i - 1][j];
          dp[i][j + nums[i]] += dp[i - 1][j];
        }
      }
    }

    return dp.back()[sum + S];
  }
};
// Runtime: 20 ms, faster than 77.45%
// Memory Usage: 21.1 MB, less than 30.77%

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int ans = 0;

    dfs(nums, S, 0, 0, ans);

    return ans;
  }

  void dfs(vector<int>& nums, int S, int sum, int idx, int& ans) {
    if (idx == nums.size()) {
      if (sum == S) {
        ++ans;
      }

      return;
    }

    dfs(nums, S, sum + nums[idx], idx + 1, ans);
    dfs(nums, S, sum - nums[idx], idx + 1, ans);
  }
};
// Runtime: 1056 ms, faster than 24.90%
// Memory Usage: 8.5 MB, less than 84.62%