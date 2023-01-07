class Solution {
 public:
  int numberOfCuts(int n) { return n == 1 ? 0 : n % 2 == 0 ? (n / 2) : n; }
};
// Runtime 3 ms
// Memory 6 MB
// 2023.1.7 at 茗筑美嘉