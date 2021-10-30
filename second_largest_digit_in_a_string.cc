class Solution {
 public:
  int secondHighest(string s) {
    int second = -1, first = -1;

    for (auto c : s) {
      if (isdigit(c)) {
        int cur = c - '0';

        if (cur > first) {
          second = first;
          first = cur;
        } else if (cur < first && cur > second) {
          second = cur;
        }
      }
    }

    return second;
  }
};
// Runtime: 4 ms, faster than 72.83%
// Memory Usage: 6.8 MB, less than 56.60%
// 2021.10.30 at 茗筑美嘉