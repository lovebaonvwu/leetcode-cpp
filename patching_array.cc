class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    long ans = 0, wanted = 1, i = 0;

    while (wanted <= n) {
      if (i < nums.size() && wanted >= nums[i]) {
        wanted += nums[i++];
      } else {
        wanted += wanted;
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 11.4 MB, less than 48.45%
// 2021.8.29 at 奥盛大厦