class Solution {
 public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = num; i >= num / 2; --i) {
      int j = 0;
      int n = i;

      while (n > 0) {
        j = j * 10 + n % 10;
        n /= 10;
      }

      if (j + i == num) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 30 ms, faster than 98.74%
// Memory Usage: 5.8 MB, less than 89.07%
// 2022.10.18 at 奥盛大厦