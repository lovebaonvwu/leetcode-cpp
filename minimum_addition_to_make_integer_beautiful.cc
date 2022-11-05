class Solution {
  int sum(long long n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }

    return sum;
  }

 public:
  long long makeIntegerBeautiful(long long n, int target) {
    long long base = 1, x = n;
    while (sum(x) > target) {
      x = x / 10 + 1;
      base *= 10;
    }
    return x * base - n;
  }
};
// Runtime 3ms
// Memory 6MB
// 2022.11.5 at 茗筑美嘉