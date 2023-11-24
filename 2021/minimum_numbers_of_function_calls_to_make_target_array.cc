class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    int zeros = 0;

    int n = nums.size();

    for (auto n : nums) {
      if (n == 0) {
        ++zeros;
      }
    }

    while (zeros < n) {
      for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 != 0) {
          --nums[i];
          ++ans;

          if (nums[i] == 0) {
            ++zeros;
          }
        }
      }

      if (zeros == n) {
        break;
      }

      for (int i = 0; i < n; ++i) {
        nums[i] /= 2;
      }

      ++ans;
    }

    return ans;
  }
};
// Runtime: 127 ms, faster than 30.58%
// Memory Usage: 25.4 MB, less than 83.16%
// 2021.10.15 at 奥盛大厦

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0, maxLen = 1;

    for (auto n : nums) {
      int bits = 0;

      while (n > 0) {
        ans += n & 1;
        ++bits;

        n >>= 1;
      }

      maxLen = max(maxLen, bits);
    }

    return ans + maxLen - 1;
  }
};
// Runtime: 67 ms, faster than 71.48%
// Memory Usage: 25.5 MB, less than 47.08%
// 2021.10.15 at 奥盛大厦