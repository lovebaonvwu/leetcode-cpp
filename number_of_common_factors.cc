class Solution {
 public:
  int commonFactors(int a, int b) {
    int ans = 0;
    for (int i = 1; i <= min(a, b); ++i) {
      if ((a % i == 0) && (b % i == 0)) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 100.00%
// 2022.10.3 at 茗筑美嘉