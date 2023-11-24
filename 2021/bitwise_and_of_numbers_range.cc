class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int count = 0;

    while (m != n) {
      m >>= 1;
      n >>= 1;

      count++;
    }

    return m << count;
  }
};
// Runtime: 20 ms, faster than 25.63%
// Memory Usage: 6.1 MB, less than 43.26%

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int x = m ^ n;

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return m & ~x;
  }
};
// Runtime: 4 ms, faster than 97.42%
// Memory Usage: 5.9 MB, less than 89.60%