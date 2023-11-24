class Solution {
 public:
  int numberOfMatches(int n) {
    int ans = 0;

    while (n > 1) {
      ans += n / 2;

      if (n & 1) {
        n = n / 2 + 1;
      } else {
        n = n / 2;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 20.79%
// 2021.9.17 at 奥盛大厦

class Solution {
 public:
  int numberOfMatches(int n) {
    int ans = 0;

    while (n > 1) {
      ans += n / 2;

      n = (n + 1) / 2;
    }

    return ans;
  }
};
// Runtime: 2 ms, faster than 13.43%
// Memory Usage: 5.9 MB, less than 68.59%
// 2021.9.17 at 奥盛大厦