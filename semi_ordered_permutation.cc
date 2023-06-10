class Solution {
 public:
  int semiOrderedPermutation(vector<int>& nums) {
    int p1 = -1, pn = -1, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 1) {
        p1 = i;
      }

      if (nums[i] == nums.size()) {
        pn = i;
      }
    }

    return p1 + (n - pn - 1) - (p1 > pn);
  }
};
// Runtime 16 ms
// Memory 46.3 MB