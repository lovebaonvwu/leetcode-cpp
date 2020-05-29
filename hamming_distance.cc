class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int a = x & (1 << i);
      int b = y & (1 << i);

      ans += (a != b);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%