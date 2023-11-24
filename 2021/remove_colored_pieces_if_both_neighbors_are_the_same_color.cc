class Solution {
 public:
  bool winnerOfGame(string colors) {
    int cntA = 0, cntB = 0;

    for (int i = 1; i < colors.size() - 1; ++i) {
      if (colors[i] == 'A' && colors[i - 1] == colors[i] &&
          colors[i + 1] == colors[i]) {
        ++cntA;
      }

      if (colors[i] == 'B' && colors[i - 1] == colors[i] &&
          colors[i + 1] == colors[i]) {
        ++cntB;
      }
    }

    return cntA > cntB;
  }
};
// Runtime: 61 ms, faster than 14.17%
// Memory Usage: 13.4 MB, less than 49.13%
// 2021.10.20 at 奥盛大厦