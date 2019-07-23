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