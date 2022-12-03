class Solution {
 public:
  bool canPermutePalindrome(string s) {
    int ch[26] = {0};
    for (auto c : s) {
      ++ch[c - 'a'];
    }

    int i = 0;
    for (int cnt = 0; i < 26 && cnt < 2; ++i) {
      if (ch[i] % 2) {
        ++cnt;
      }
    }

    return i == 26;
  }
};
// Runtime 0 ms
// Memory 6.1 MB
// 2022.12.3 at 茗筑美嘉