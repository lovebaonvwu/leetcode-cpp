class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      if ((c >> i) & 1) {
        if (!((a >> i) & 1) && !((b >> i) & 1)) {
          ++ans;
        }
      } else {
        if ((a >> i) & 1) {
          ++ans;
        }

        if ((b >> i) & 1) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%