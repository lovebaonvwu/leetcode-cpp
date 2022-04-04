class Solution {
 public:
  int minBitFlips(int start, int goal) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      ans += (start & 1) ^ (goal & 1);
      start >>= 1;
      goal >>= 1;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 28.57%
// 2022.4.4 at 茗筑美嘉