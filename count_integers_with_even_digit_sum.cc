class Solution {
 public:
  int countEven(int num) {
    int ans = 0;

    for (int i = 1; i <= num; ++i) {
      int sum = 0, n = i;

      while (n > 0) {
        sum += n % 10;
        n /= 10;
      }

      ans += (sum % 2 == 0);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 30.01%
// Memory Usage: 5.8 MB, less than 72.07%
// 2022.3.19 at 茗筑美嘉