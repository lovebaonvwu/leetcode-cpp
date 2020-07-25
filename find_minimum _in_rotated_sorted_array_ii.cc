class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] < nums[hi]) {
        hi = mid;
      } else if (nums[mid] > nums[hi]) {
        lo = mid + 1;
      } else {
        if (nums[mid] > nums[mid + 1]) {
          return nums[mid + 1];
        }

        --hi;
      }
    }

    return nums[lo];
  }
};
// Runtime: 8 ms, faster than 96.81%
// Memory Usage: 12.5 MB, less than 31.63%

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] < nums[hi]) {
        hi = mid;
      } else if (nums[mid] > nums[hi]) {
        lo = mid + 1;
      } else {
        --hi;
      }
    }

    return nums[lo];
  }
};
// Runtime: 28 ms, faster than 7.85%
// Memory Usage: 12.4 MB, less than 51.21%