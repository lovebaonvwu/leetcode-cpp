class Solution {
 public:
  int minimumNumbers(int num, int k) {
    if (num == 0) {
      return 0;
    }

    int ans = -1;
    int ud = num % 10;

    for (int i = 1; i <= 10; ++i) {
      int mul = k * i;
      if (mul % 10 == ud && mul <= num) {
        ans = i;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 6 ms, faster than 31.92%
// Memory Usage: 5.9 MB, less than 45.47%
// 2022.6.23 at 奥盛大厦