class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int step = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      --step;

      if (step < 0) {
        return false;
      }

      if (nums[i] > step) {
        step = nums[i];
      }
    }

    return true;
  }
};
// Runtime: 8 ms, faster than 97.06%
// Memory Usage: 9.9 MB, less than 96.05%

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int reach = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (reach < i) {
        return false;
      }

      reach = max(reach, i + nums[i]);
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 71.96%
// Memory Usage: 10 MB, less than 76.32%

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();

    vector<bool> reached(n);
    reached[n - 1] = true;

    for (int i = n - 2; i >= 0; --i) {
      for (int j = 1; j <= nums[i] && i + j < n; ++j) {
        if (reached[i + j]) {
          reached[i] = true;
          break;
        }
      }
    }

    return reached[0];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    vector<vector<int>> dp(nums.size());

    return dfs(nums, dp, 0);
  }

  bool dfs(vector<int>& nums, vector<vector<int>>& dp, int pos) {
    if (pos >= nums.size()) {
      return false;
    }

    if (pos + nums[pos] >= nums.size() - 1) {
      return true;
    }

    for (int i = 1; i <= nums[pos]; ++i) {
      if (dp[pos].size() < i + 1) {
        dp[pos].resize(i + 1);
      }

      if (dp[pos][i]) {
        continue;
      }
      if (dfs(nums, dp, pos + i)) {
        return true;
      }
      dp[pos][i] = 1;
    }

    return false;
  }
};
// Time Limit Exceeded