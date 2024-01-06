class Solution {
 public:
  int findKOr(vector<int>& nums, int k) {
    int ans = 0;
    for (int i = 0; i < 31; ++i) {
      int cnt = 0;
      for (auto n : nums) {
        if (n & (1 << i)) {
          ++cnt;
        }
      }

      if (cnt >= k) {
        ans |= 1 << i;
      }
    }

    return ans;
  }
};
// 4ms
// 25.73MB