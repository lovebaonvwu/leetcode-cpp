class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    if (n == 1) {
      return true;
    }

    while (n > 1) {
      if (n % 2 != 0) {
        return false;
      }

      n >>= 1;
    }

    return true;
  }
};

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    int bits_count = 0;

    while (n) {
      ++bits_count;

      n = n & n - 1;
    }

    return bits_count == 1;
  }
};