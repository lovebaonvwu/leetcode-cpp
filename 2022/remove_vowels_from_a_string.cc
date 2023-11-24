class Solution {
 public:
  string removeVowels(string s) {
    int i = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' &&
          s[j] != 'u') {
        s[i++] = s[j];
      }
    }

    return s.substr(0, i);
  }
};
// Runtime 0 ms
// Memory 6.4 MB
// 2022.11.24 at 茗筑美嘉