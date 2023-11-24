class Solution {
 public:
  int vowelStrings(vector<string>& words, int left, int right) {
    int ans = 0;

    for (int i = left; i <= right; ++i) {
      ans += isVowel(words[i][0]) && isVowel(words[i].back());
    }

    return ans;
  }

 private:
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
// Runtime 24 ms
// Memory 31.6 MB