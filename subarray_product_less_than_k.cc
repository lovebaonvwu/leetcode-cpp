class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans = 0;
    int n = nums.size();

    for (int i = 0, j = 0, mul = 1; j < n; ++j) {
      mul *= nums[j];

      while (i <= j && mul >= k) {
        mul /= nums[i++];
      }

      ans += j - i + 1;
    }

    return ans;
  }
};
// Runtime: 240 ms, faster than 97.86%
// Memory Usage: 92.1 MB, less than 19.05%