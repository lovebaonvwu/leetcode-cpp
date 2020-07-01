class Solution {
 public:
  int kthFactor(int n, int k) {
    int ans = -1;
    for (int i = 1; i < n + 1 && k > 0; ++i) {
      if (n % i == 0) {
        ans = i;
        --k;
      }
    }

    return k == 0 ? ans : -1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 66.67%

class Solution {
 public:
  int kthFactor(int n, int k) {
    int i = 1;
    for (; i * i < n + 1; ++i) {
      if (n % i == 0 && --k == 0) {
        return i;
      }
    }

    --i;
    for (; i >= 1; --i) {
      if (i * i == n) {
        continue;
      }

      if (n % i == 0 && --k == 0) {
        return n / i;
      }
    }

    return -1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 66.67%