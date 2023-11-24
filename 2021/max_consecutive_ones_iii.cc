class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int ans = 0;
    int i = 0, j = 0;

    for (; j < nums.size(); ++j) {
      if (nums[j] == 0) {
        --k;
      }

      if (k < 0) {
        if (nums[i] == 0) {
          ++k;
        }

        ++i;
      }
    }

    return j - i;
  }
};
// Runtime: 48 ms, faster than 89.00%
// Memory Usage: 55.5 MB, less than 22.02%