class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      if (nums[md] == target) {
        return md;
      }

      if (nums[md] < nums[hi]) {
        if (target > nums[md] && target <= nums[hi]) {
          lo = md + 1;
        } else {
          hi = md - 1;
        }
      } else {
        if (target < nums[md] && target >= nums[lo]) {
          hi = md - 1;
        } else {
          lo = md + 1;
        }
      }
    }

    return -1;
  }
};
// Runtime: 4 ms, faster than 79.53%
// Memory Usage: 8.7 MB, less than 83.13%