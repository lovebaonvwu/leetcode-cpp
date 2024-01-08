class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int cnt[31] = {0};
    for (auto n : nums) {
      for (int i = 0; i < 31; ++i) {
        if (n & (1 << i)) {
          ++cnt[i];
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < 31; ++i) {
      if (k & (1 << i)) {
        if (cnt[i] % 2 == 0) {
          ++ans;
        }
      } else {
        if (cnt[i] % 2 == 1) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 172ms
// 88.95MB