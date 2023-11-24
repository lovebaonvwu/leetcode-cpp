class Solution {
 public:
  bool isPowerOfThree(int n) {
    while (n > 0 && n % 3 == 0) {
      n /= 3;
    }

    return n == 1;
  }
};  // 8ms

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }

    if (n == 1) {
      return true;
    }

    while (n > 1) {
      if (n % 3 != 0) {
        return false;
      }

      n /= 3;
    }

    return true;
  }
};  // 16ms