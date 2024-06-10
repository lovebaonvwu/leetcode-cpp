class Solution {
 public:
  int numberOfChild(int n, int k) {
    int d = k / (n - 1);
    return d % 2 == 0 ? (0 + k % (n - 1)) : (n - 1 - k % (n - 1));
  }
};
// 0 ms
// 7.41 MB