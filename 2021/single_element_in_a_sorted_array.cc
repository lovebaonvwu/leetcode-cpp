class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) {
      int mid = i + (j - i) / 2;

      int r = (mid - i) % 2;

      if (mid == 0 || mid == nums.size() - 1) {
        return nums[mid];
      }

      if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
        return nums[mid];
      } else if (nums[mid] == nums[mid - 1] && !r) {
        j = mid - 2;
      } else if (nums[mid] == nums[mid - 1] && r) {
        i = mid + 1;
      } else if (nums[mid] == nums[mid + 1] && !r) {
        i = mid + 2;
      } else if (nums[mid] == nums[mid + 1] && r) {
        j = mid - 1;
      }
    }

    return -1;
  }
};
// Runtime: 20 ms, faster than 38.21%
// Memory Usage: 11.2 MB, less than 20.58%

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) {
      int mid = i + (j - i) / 2;

      if (mid == 0 || mid == nums.size() - 1 ||
          (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])) {
        return nums[mid];
      }

      int nextRoundHasOddNums = (mid - i) % 2;

      if (nums[mid] == nums[mid - 1]) {
        if (nextRoundHasOddNums) {
          i = mid + 1;
        } else {
          j = mid - 2;
        }
      } else {
        if (nextRoundHasOddNums) {
          j = mid - 1;
        } else {
          i = mid + 2;
        }
      }
    }

    return -1;
  }
};
// Runtime: 16 ms, faster than 84.75%
// Memory Usage: 11.3 MB, less than 12.84%