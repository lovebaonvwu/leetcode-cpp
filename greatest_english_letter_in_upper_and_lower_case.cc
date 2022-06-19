class Solution {
 public:
  string greatestLetter(string s) {
    int cnt[256] = {0};
    for (auto c : s) {
      ++cnt[c];
    }

    for (char i = 'Z'; i >= 'A'; --i) {
      if (cnt[i] > 0 && cnt[i + 0x20] > 0) {
        return string(1, i);
      }
    }

    return "";
  }
};
// Runtime: 6 ms, faster than 20.00%
// Memory Usage: 6.7 MB, less than 60.00%
// 2022.6.19 at 茗筑美嘉