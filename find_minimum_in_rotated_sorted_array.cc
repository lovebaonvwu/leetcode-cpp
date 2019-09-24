class Solution {
 public:
  int findMin(vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      if (nums[md] > nums[hi]) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return nums[hi];
  }
};
// Runtime: 4 ms, faster than 76.05%
// Memory Usage: 8.7 MB, less than 97.78%

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi) {
      if (nums[lo] < nums[hi]) {
        return nums[lo];
      }

      int md = lo + (hi - lo) / 2;

      if (nums[md] >= nums[lo]) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return nums[lo];
  }
};
// Runtime: 8 ms, faster than 7.36%
// Memory Usage: 8.7 MB, less than 84.44%