class Solution {
 public:
  int arrangeCoins(int n) {
    int i = 1;

    while (n >= i) {
      n -= i;
      ++i;
    }

    return i - 1;
  }
};  // 12ms

class Solution {
 public:
  int arrangeCoins(int n) {
    long cnt = 0;
    int i = 1;

    while (cnt <= n) {
      cnt += i;
      ++i;
    }

    return i - 2;
  }
};  // 12ms

class Solution {
 public:
  int arrangeCoins(int n) {
    int lo = 1;
    int hi = n;

    int ans = 0;
    while (lo <= hi) {
      long long md = lo + (hi - lo) / 2;

      if (md * (md + 1) / 2 <= n) {
        ans = md;
        lo = md + 1;
      } else {
        hi = md - 1;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 79.21%
// Memory Usage: 6.1 MB, less than 21.61%