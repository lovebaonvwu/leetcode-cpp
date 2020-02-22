class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double a1 = minutes * 6;
    double a2 = (hour % 12) * 30 + a1 / 360 * 30;

    if (a2 > a1) {
      swap(a1, a2);
    }

    double ans = a1 - a2;

    if (ans > 180) {
      ans = 360 - ans;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 100.00%