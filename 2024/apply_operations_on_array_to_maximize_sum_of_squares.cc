class Solution {
 public:
  int maxSum(vector<int>& nums, int k) {
    int cnt[32]{0};
    for (auto n : nums) {
      for (int i = 0; i < 32; ++i) {
        if (n & (1 << i)) {
          ++cnt[i];
        }
      }
    }

    int ans = 0;
    int mod = 1e9 + 7;
    while (k-- > 0) {
      int cur = 0;
      for (int i = 0; i < 32; ++i) {
        if (cnt[i] > 0) {
          --cnt[i];
          cur |= 1 << i;
        }
      }

      ans = (ans + 1LL * cur * cur % mod) % mod;
    }

    return ans;
  }
};
// 177 ms
// 86.02 MB