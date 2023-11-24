class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int l = -1, r = -1;

    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > right) {
        l = i;
        r = i;
      } else if (nums[i] >= left) {
        r = i;
      }

      ans += r - l;
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 93.40%
// Memory Usage: 32.5 MB, less than 50.35%