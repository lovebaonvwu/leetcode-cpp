class Solution {
  bool isVowel(char c) {
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' || c == 'u' || c == 'U') {
      return true;
      ;
    }

    return false;
  }

 public:
  bool halvesAreAlike(string s) {
    int c1 = 0;
    int c2 = 0;

    for (int i = 0, j = s.size() / 2; j < s.size(); ++i, ++j) {
      if (isVowel(s[i])) {
        ++c1;
      }

      if (isVowel(s[j])) {
        ++c2;
      }
    }

    return c1 == c2;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 53.76%