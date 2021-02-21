class Solution {
 public:
  int brokenCalc(int X, int Y) {
    int cnt = 0;

    while (Y > X) {
      ++cnt;

      if (Y & 1) {
        Y += 1;
      } else {
        Y /= 2;
      }
    }

    return cnt + X - Y;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 51.42%