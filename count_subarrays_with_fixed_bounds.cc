class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;
    for (int n = nums.size(), i = 0, j = -1, pmax = -1, pmin = -1; i < n; ++i) {
      if (nums[i] < minK || nums[i] > maxK) {
        j = i;
      }
      if (nums[i] == minK) {
        pmin = i;
      }
      if (nums[i] == maxK) {
        pmax = i;
      }

      ans += max(0, min(pmin, pmax) - j);
    }

    return ans;
  }
};
// Runtime 109 ms
// Memory 70.4 MB
// Sliding Window
// Two pointers