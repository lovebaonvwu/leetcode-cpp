class Solution {
 public:
  vector<int> largestSubarray(vector<int>& nums, int k) {
    int pos = 0;
    for (int i = 0, cur = 0; i <= nums.size() - k; ++i) {
      if (nums[i] > cur) {
        cur = nums[i];
        pos = i;
      }
    }

    return vector<int>(nums.begin() + pos, nums.begin() + pos + k);
  }
};
// Runtime 158 ms
// Memory 71.8 MB
// 2023.1.26 at 茗筑美嘉