class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int ans = -1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] > nums[i]) {
          ans = max(ans, nums[j] - nums[i]);
        }
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 30.77%
// Memory Usage: 8.2 MB, less than 61.54%
// 2021.9.27 at  奥盛大厦

class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int ans = -1;

    for (int i = 1, prev = nums[0]; i < nums.size(); ++i) {
      if (nums[i] > prev) {
        ans = max(ans, nums[i] - prev);
      }

      prev = min(prev, nums[i]);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 84.62%
// Memory Usage: 8.4 MB, less than 7.69%
// 2021.9.27 at 奥盛大厦