class Solution {
 public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int t = x;
    int sum = 0;
    while (t > 0) {
      sum += t % 10;
      t /= 10;
    }

    return x % sum == 0 ? sum : -1;
  }
};
// 0 ms
// 7.15 MB