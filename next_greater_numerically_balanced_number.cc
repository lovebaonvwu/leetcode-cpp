class Solution {
 public:
  int nextBeautifulNumber(int n) {
    for (int i = n + 1;; ++i) {
      if (balanced(i)) {
        return i;
      }
    }

    return -1;
  }

  bool balanced(int n) {
    int cnt[9] = {0};

    while (n > 0) {
      int r = n % 10;

      if (r == 0) {
        return false;
      }

      ++cnt[r - 1];
      n /= 10;
    }

    for (int i = 1; i <= 9; ++i) {
      if (cnt[i - 1] > 0 && cnt[i - 1] != i) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 89 ms, faster than 92.00%
// Memory Usage: 5.8 MB, less than 96.00%
// 2021.10.25 at 奥盛大厦