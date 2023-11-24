class Solution {
 public:
  bool canWinNim(int n) { return n % 4 != 0; }
};  // 0ms

class Solution {
 public:
  bool canWinNim(int n) { return (n & 3) != 0; }
};  // 0ms