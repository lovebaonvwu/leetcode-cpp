class Solution {
  bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
           c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  string sortVowels(string s) {
    string t = s;
    sort(t.begin(), t.end());

    int n = s.size();
    for (int i = 0, j = 0; i < n;) {
      while (i < n && !isVowel(s[i])) {
        ++i;
      }

      while (j < n && !isVowel(t[j])) {
        ++j;
      }

      if (i < n && j < n) {
        s[i++] = t[j++];
      }
    }

    return s;
  }
};
// 53ms
// 11.27mb