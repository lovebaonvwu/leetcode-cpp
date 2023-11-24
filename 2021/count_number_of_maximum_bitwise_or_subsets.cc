class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int maxXor = 0;

    for (auto n : nums) {
      maxXor |= n;
    }

    int n = nums.size();

    int ans = 0;
    for (int i = pow(2, n) - 1; i >= 0; --i) {
      int curXor = 0;

      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          curXor |= nums[j];
        }
      }

      if (curXor == maxXor) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 92 ms, faster than 60.38%
// Memory Usage: 8.4 MB, less than 85.87%
// 2021.11.12 at 奥盛大厦

class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int dp[1 << 17] = {1}, max = 0;

    for (auto n : nums) {
      for (int i = max; i >= 0; --i) {
        dp[i | n] += dp[i];
      }

      max |= n;
    }

    return dp[max];
  }
};
// Runtime: 120 ms, faster than 45.76%
// Memory Usage: 9 MB, less than 36.01%
// 2021.11.12 at 奥盛大厦