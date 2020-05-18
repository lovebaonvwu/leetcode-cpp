class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        int tmp = nums[i];

        nums[i] = nums[i + 1];
        if (is_sorted(nums.begin(), nums.end())) {
          return true;
        }

        nums[i] = nums[i + 1] = tmp;
        if (is_sorted(nums.begin(), nums.end())) {
          return true;
        }

        return false;
      }
    }

    return true;
  }
};
// Runtime: 96 ms, faster than 8.37%
// Memory Usage: 26.9 MB, less than 5.00%

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int cnt = 0;

    for (int i = 0; i < nums.size() - 1 && cnt <= 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        ++cnt;

        if (i - 1 < 0 || nums[i - 1] <= nums[i + 1]) {
          nums[i] = nums[i + 1];
        } else {
          nums[i + 1] = nums[i];
        }
      }
    }

    return cnt <= 1;
  }
};
// Runtime: 60 ms, faster than 24.89%
// Memory Usage: 26.9 MB, less than 5.00%