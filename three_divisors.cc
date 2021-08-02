class Solution {
 public:
  bool isThree(int n) {
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      if (n % i == 0) {
        ++cnt;
      }

      if (cnt > 3) {
        break;
      }
    }

    return cnt == 3;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 33.33%
// 2021.8.2 at 奥盛大厦