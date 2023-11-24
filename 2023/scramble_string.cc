class Solution {
  unordered_map<string, bool> memo;

 public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }

    string m = s1 + " " + s2;
    if (memo.find(m) != memo.end()) {
      return memo[m];
    }

    int len = s1.size();

    int cnt[26] = {0};
    for (int i = 0; i < len; ++i) {
      ++cnt[s1[i] - 'a'];
      --cnt[s2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (cnt[i] != 0) {
        return false;
      }
    }

    for (int i = 1; i < len; ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i))) {
        return memo[m] = true;
      }

      if (isScramble(s1.substr(0, i), s2.substr(len - i)) &&
          isScramble(s1.substr(i), s2.substr(0, len - i))) {
        return memo[m] = true;
      }
    }

    return memo[m] = false;
  }
};
// Runtime 11 ms
// Memory 13.2 MB