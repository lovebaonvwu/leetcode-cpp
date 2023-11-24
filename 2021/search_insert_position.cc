class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0)
      return 0;

    if (target < nums[0])
      return 0;
    if (target > nums[nums.size() - 1])
      return nums.size();

    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) {
      int mid = (i + j) >> 1;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        j = mid - 1;
      } else {
        i = mid + 1;
      }
    }

    return i;
  }
};