class Solution {
 public:
  long long maxScore(vector<int>& nums, int x) {
    long long odd = nums[0];
    long long even = nums[0];
    if (nums[0] % 2) {
      even -= x;
    } else {
      odd -= x;
    }

    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] % 2 == 0) {
        even = max(nums[i] + even, nums[i] + odd - x);
      } else {
        odd = max(nums[i] + odd, nums[i] + even - x);
      }
    }

    return max(odd, even);
  }
};
// 211ms
// 99.54mb