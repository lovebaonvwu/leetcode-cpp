class Solution {
 public:
  bool check(vector<int>& nums) {
    int n = nums.size(), cnt = 0;

    for (int i = 0; i < n; ++i) {
      if (nums[i] > nums[(i + 1) % n]) {
        ++cnt;
      }

      if (cnt > 1) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 4 ms, faster than 48.45%
// Memory Usage: 8.3 MB, less than 77.07%
// 2021.8.18 at 奥盛大厦