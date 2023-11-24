class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans{-1, -1};

    ans[0] = findFirst(nums, target);
    ans[1] = findLast(nums, target);

    return ans;
  }

  int findFirst(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (nums[mid] == target) {
        if (mid > 0 && nums[mid - 1] == target) {
          hi = mid - 1;
        } else {
          return mid;
        }
      } else if (nums[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return -1;
  }

  int findLast(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (nums[mid] == target) {
        if (mid + 1 < nums.size() && nums[mid + 1] == target) {
          lo = mid + 1;
        } else {
          return mid;
        }
      } else if (nums[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return -1;
  }
};