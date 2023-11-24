class Solution {
 public:
  int getLucky(string s, int k) {
    int sum = 0;

    for (auto c : s) {
      int n = (c - 'a') + 1;

      if (n < 10) {
        sum += n;
      } else {
        while (n > 0) {
          sum += n % 10;
          n /= 10;
        }
      }
    }

    while (--k > 0) {
      int tmp = 0;

      while (sum > 0) {
        tmp += sum % 10;
        sum /= 10;
      }

      sum = tmp;
    }

    return sum;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%
// 2021.7.26 at 奥盛大厦