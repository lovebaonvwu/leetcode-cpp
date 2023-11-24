class Solution {
 public:
  bool checkPowersOfThree(int n) {
    int lo = 0, hi = 0;

    while (pow(3, hi) < n) {
      ++hi;
    }

    vector<bool> used(hi + 1);
    int prev = n;

    while (n > 0) {
      for (int i = hi; i >= 0; --i) {
        int t = pow(3, i);

        if (t <= n && !used[i]) {
          n -= t;
          used[i] = true;
        }
      }

      if (n == prev) {
        break;
      }

      prev = n;
    }

    return n == 0;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 9.42%

class Solution {
 public:
  bool checkPowersOfThree(int n) {
    int lo = 0, hi = 0;

    while (pow(3, hi) < n) {
      ++hi;
    }

    int prev = n;

    while (n > 0) {
      for (int i = hi; i >= 0; --i) {
        int t = pow(3, i);

        if (t <= n) {
          n -= t;
          hi = i - 1;
        }
      }

      if (n == prev) {
        break;
      }

      prev = n;
    }

    return n == 0;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 18.22%

class Solution {
 public:
  bool checkPowersOfThree(int n) {
    if (n == 1) {
      return true;
    }

    if (n % 3 == 0) {
      return checkPowersOfThree(n / 3);
    }

    if (n % 3 == 1) {
      return checkPowersOfThree((n - 1) / 3);
    }

    return false;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 76.58%