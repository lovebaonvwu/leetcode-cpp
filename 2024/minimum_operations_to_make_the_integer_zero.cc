class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    long long x = num1;
    long long y = num2;

    int k = 1;
    while (true) {
      x -= y;
      if (x < k)
        return -1;
      int cnt = __builtin_popcountll(x);
      if (cnt <= k)
        return k;
      ++k;
    }

    return -1;
  }
};
// 4 ms
// 7.34 MB