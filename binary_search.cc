class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return -1;
  }
};
// Runtime: 76 ms, faster than 86.68%
// Memory Usage: 27.9 MB, less than 16.91%