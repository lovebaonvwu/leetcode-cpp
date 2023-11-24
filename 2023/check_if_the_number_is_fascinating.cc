class Solution {
 public:
  bool isFascinating(int n) {
    if (n > 333) {
      return false;
    }

    n = n * 1000000 + n * 2 * 1000 + n * 3;

    int cnt[10] = {0};

    while (n > 0) {
      int d = n % 10;
      if (d == 0) {
        return false;
      }

      if (cnt[d] > 0) {
        return false;
      }

      ++cnt[d];
      n /= 10;
    }

    return true;
  }
};
// Runtime 0 ms
// Memory 6.1 MB