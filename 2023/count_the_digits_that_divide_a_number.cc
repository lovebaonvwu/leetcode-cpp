class Solution {
 public:
  int countDigits(int num) {
    int t = num;
    int ans = 0;
    while (t > 0) {
      ans += num % (t % 10) == 0;
      t /= 10;
    }

    return ans;
  }
};
// Runtime 3 ms
// Memory 6 MB
// 2023.1.1 at 茗筑美嘉