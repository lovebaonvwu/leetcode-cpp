class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    return max(rb(nums1), rb(nums2));
  }

  int rb(vector<int>& nums) {
    vector<int> dp(nums.size());

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[nums.size() - 1];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.6 MB, less than 91.43%

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    int a = nums[0];
    int b = nums[1];

    int ans1 = max(a, b);
    for (int i = 2; i < nums.size() - 1; ++i) {
      ans1 = max(nums[i] + a, b);

      a = max(a, b);
      b = ans1;
    }

    a = nums[1];
    b = nums[2];

    int ans2 = max(a, b);
    for (int i = 3; i < nums.size(); ++i) {
      ans2 = max(nums[i] + a, b);

      a = max(a, b);
      b = ans2;
    }

    return max(ans1, ans2);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    vector<int> dp1(nums.size() - 1, -1);
    vector<int> dp2(nums.size() - 1, -1);

    return max(rb(nums1, 0, dp1), rb(nums2, 0, dp2));
  }

  int rb(vector<int>& nums, int begin, vector<int>& dp) {
    if (begin >= nums.size()) {
      return 0;
    }

    if (begin == nums.size() - 1) {
      dp[begin] = nums[nums.size() - 1];
      return dp[begin];
    }

    if (dp[begin] > -1) {
      return dp[begin];
    }

    dp[begin] = max(nums[begin] + rb(nums, begin + 2, dp),
                    nums[begin + 1] + rb(nums, begin + 3, dp));

    return dp[begin];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 22.86%

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> nums1(nums.begin(), nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());

    return max(rb(nums1), rb(nums2));
  }

  int rb(vector<int>& nums) {
    int a = 0;
    int b = 0;
    int res = 0;

    for (int i = 0; i < nums.size(); ++i) {
      res = max(nums[i] + a, b);
      a = b;
      b = res;
    }

    return res;
  }
};
// Runtime: 4 ms, faster than 58.14%
// Memory Usage: 8.6 MB, less than 85.71%

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    return rb(nums, 0, nums.size() - 1, dp);
  }

  int rb(vector<int>& nums, int begin, int end, vector<vector<int>>& dp) {
    if (begin > end) {
      return 0;
    }

    if (begin == end) {
      dp[begin][end] = nums[begin];
      return nums[begin];
    }

    if (dp[begin][end] > -1) {
      return dp[begin][end];
    }

    if (begin == 0) {
      dp[begin][end] =
          max(nums[0] + rb(nums, 2, end - 1, dp), rb(nums, 1, end, dp));
      return dp[begin][end];
    }

    dp[begin][end] = max(nums[begin] + rb(nums, begin + 2, end, dp),
                         nums[begin + 1] + rb(nums, begin + 3, end, dp));

    return dp[begin][end];
  }
};
// Runtime: 4 ms, faster than 57.97%
// Memory Usage: 9.2 MB, less than 5.72%