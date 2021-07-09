class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};
// Runtime: 40 ms, faster than 46.83%
// Memory Usage: 8.6 MB, less than 98.44%

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp(nums.size(), -1);

    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int res = lis(nums, i, dp);
      ans = res > ans ? res : ans;
    }

    return ans;
  }

  int lis(vector<int>& nums, int tail, vector<int>& dp) {
    if (tail == 0) {
      return 1;
    }

    if (dp[tail] > -1) {
      return dp[tail];
    }

    int max = 0;
    for (int i = tail - 1; i >= 0; --i) {
      if (nums[tail] > nums[i]) {
        int res = lis(nums, i, dp);
        max = res > max ? res : max;
      }
    }

    dp[tail] = max + 1;

    return dp[tail];
  }
};
// Runtime: 44 ms, faster than 31.41%
// Memory Usage: 9 MB, less than 10.94%

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> result;

    for (auto n : nums) {
      auto it = lower_bound(result.begin(), result.end(), n);

      if (it == result.end()) {
        result.push_back(n);
      } else {
        result[it - result.begin()] = n;
      }
    }

    return result.size();
  }
};
// Runtime: 12 ms, faster than 76.08%
// Memory Usage: 10.3 MB, less than 96.36%
// 2021.7.9 at 奥盛大厦