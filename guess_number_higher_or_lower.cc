// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    long lo = 1;
    long hi = n;

    while (lo <= hi) {
      long mid = (lo + hi) >> 1;

      if (guess(mid) > 0) {
        lo = ++mid;
      } else if (guess(mid) < 0) {
        hi = --mid;
      } else {
        return mid;
      }
    }

    return -1;
  }
};  // 4ms