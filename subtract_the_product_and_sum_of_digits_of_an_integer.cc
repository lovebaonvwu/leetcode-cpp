class Solution {
 public:
  int subtractProductAndSum(int n) {
    int p = 1;
    int s = 0;

    while (n > 0) {
      int r = n % 10;

      p *= r;
      s += r;

      n /= 10;
    }

    return p - s;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 100.00%