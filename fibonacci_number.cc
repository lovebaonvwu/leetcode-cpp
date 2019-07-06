class Solution {
 public:
  int fib(int N) {
    if (N < 2) {
      return N;
    }

    int a = 0;
    int b = 1;
    int ans = 0;

    for (int i = 2; i <= N; ++i) {
      ans = a + b;
      a = b;
      b = ans;
    }

    return ans;
  }
};