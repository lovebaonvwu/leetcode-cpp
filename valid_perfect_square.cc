class Solution {
 public:
  bool isPerfectSquare(int num) {
    int lo = 1;
    int hi = num;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;

      float tmp = num * 1. / mid;

      if (mid < tmp) {
        lo = mid + 1;
      } else if (mid > tmp) {
        hi = mid - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};  // 100ms

class Solution {
 public:
  bool isPerfectSquare(int num) {
    long lo = 1;
    long hi = num;

    while (lo <= hi) {
      long mi = 0;
      mi = (lo + hi) >> 1;

      long tmp = mi * mi;

      if (tmp == num) {
        return true;
      } else if (tmp < num) {
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }

    return false;
  }
};  // 4ms

class Solution {
 public:
  bool isPerfectSquare(int num) {
    long n = num;

    while (n * n > num) {
      n = (n + num / n) / 2;
    }

    return n * n == num;
  }
};  // 4ms