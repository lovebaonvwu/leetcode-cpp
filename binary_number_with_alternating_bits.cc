class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int d = n & 1;

    while ((n & 1) == d) {
      d = 1 - d;
      n >>= 1;
    }

    return n == 0;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.1 MB, less than 100.00%

class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int prev = -1;
    while (n > 0) {
      int r = n % 2;

      if (prev == r) {
        return false;
      }

      prev = r;

      n /= 2;
    }

    return true;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.1 MB, less than 100.00%

class Solution {
 public:
  bool hasAlternatingBits(int n) {
    long x = n ^ (n >> 1);

    return ((x + 1) & x) == 0;
  }
};
// Runtime: 4 ms, faster than 51.95%
// Memory Usage: 8.1 MB, less than 92.86%