class Solution {
 public:
  int kthGrammar(int n, int k) {
    if (k == 1) {
      return 0;
    }

    if (k == 2) {
      return 1;
    }

    int size = pow(2, n);
    if (k <= size / 2) {
      return kthGrammar(n - 1, k);
    } else if (k <= (size / 4 * 3)) {
      return kthGrammar(n - 1, k - size / 2 + size / 4);
    } else {
      return kthGrammar(n - 1, k - size / 4 * 3);
    }
  }
};
// 0ms
// 6.32MB