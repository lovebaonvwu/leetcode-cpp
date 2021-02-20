class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();

    vector<int> hi(n);
    vector<int> lo(n);

    hi[0] = nums[0];
    lo[0] = nums[0];

    int lowest = lo[0], highest = hi[0];

    for (int i = 1; i < n; ++i) {
      lo[i] = min(nums[i], lo[i - 1] + nums[i]);
      hi[i] = max(nums[i], hi[i - 1] + nums[i]);

      lowest = min(lowest, lo[i]);
      highest = max(highest, hi[i]);
    }

    return max(highest, abs(lowest));
  }
};
// Runtime: 60 ms, faster than 82.72%
// Memory Usage: 44.6 MB, less than 7.53%

class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();

    int hi = nums[0];
    int lo = nums[0];

    int lowest = lo, highest = hi;

    for (int i = 1; i < n; ++i) {
      lo = min(nums[i], lo + nums[i]);
      hi = max(nums[i], hi + nums[i]);

      lowest = min(lowest, lo);
      highest = max(highest, hi);
    }

    return max(highest, abs(lowest));
  }
};
// Runtime: 48 ms, faster than 98.66%
// Memory Usage: 41.3 MB, less than 63.82%