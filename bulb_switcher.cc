class Solution {
 public:
  int bulbSwitch(int n) {
    int ans = 0;

    for (int i = 1; i * i <= n; ++i) {
      ++ans;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 74.43%
// 2021.10.29 at 奥盛大厦