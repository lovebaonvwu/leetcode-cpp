class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int md = lo + (hi - lo) / 2;

      if (nums[md] == target) {
        return true;
      }

      if (nums[md] < nums[hi]) {
        if (target > nums[md] && target <= nums[hi]) {
          lo = md + 1;
        } else {
          hi = md - 1;
        }
      } else if (nums[md] > nums[hi]) {
        if (target < nums[md] && target >= nums[lo]) {
          hi = md - 1;
        } else {
          lo = md + 1;
        }
      } else {
        --hi;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 98.13%
// Memory Usage: 8.6 MB, less than 100.00%