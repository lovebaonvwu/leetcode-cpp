class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return 1;
    }

    vector<int> nums(n + 1);

    nums[0] = 0;
    nums[1] = 1;

    int ans = 1;

    for (int i = 2; i < nums.size(); ++i) {
      if (i & 1) {
        nums[i] = nums[i / 2] + nums[i / 2 + 1];
      } else {
        nums[i] = nums[i / 2];
      }

      ans = max(ans, nums[i]);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 61.73%