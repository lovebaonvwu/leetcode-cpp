class Solution {
 public:
  int monkeyMove(int n) {
    long long ans = 1, mod = 1e9 + 7;
    long long base = 2;

    while (n > 0) {
      if (n % 2 == 1) {
        ans = ans * base % mod;
      }

      base = base * base % mod;
      n /= 2;
    }

    return (ans - 2 + mod) % mod;
  }
};
// Runtime 3 ms
// Memory 5.9 MB