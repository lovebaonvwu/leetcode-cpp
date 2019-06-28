class Solution {
 public:
  int mySqrt(int x) {
    int lo = 1;
    int hi = x;
    int ans = 0;

    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;

      if (mi <= x / mi) {
        lo = mi + 1;
        ans = mi;
      } else {
        hi = mi - 1;
      }
    }

    return ans;
  }
};  // 0ms

class Solution {
 public:
  int mySqrt(int x) {
    int lo = 0;
    int hi = x;

    while (lo <= hi) {
      long mi = (lo + hi) >> 1;

      if (mi * mi == x) {
        return mi;
      } else if (mi * mi > x) {
        hi = mi - 1;
      } else if (mi * mi < x && (mi + 1) * (mi + 1) > x) {
        return mi;
      } else {
        lo = mi + 1;
      }
    }

    return -1;
  }
};  // 4ms