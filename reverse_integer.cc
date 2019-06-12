class Solution {
 public:
  int reverse(int x) {
    bool sign = false;
    long n = 0, r;

    while (x) {
      n = n * 10 + x % 10;

      x /= 10;
    }

    if (n > INT_MAX || n < INT_MIN) {
      return 0;
    }

    return n;
  }
};  // 4ms

class Solution {
 public:
  int reverse(int x) {
    bool sign = false;
    long n = 0, r, m;

    m = x;

    if (m < 0) {
      sign = true;
      m = -m;
    }

    while (m > 0) {
      r = m % 10;
      m /= 10;

      n = n * 10 + r;
    }

    if (sign) {
      n = -n;
    }

    if (n > INT_MAX || n < INT_MIN) {
      return 0;
    }

    return n;
  }
};  // 4ms