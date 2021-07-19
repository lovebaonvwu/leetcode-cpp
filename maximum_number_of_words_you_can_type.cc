class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    int broken[26] = {0};

    for (auto l : brokenLetters) {
      broken[l - 'a'] = 1;
    }

    stringstream ss(text);

    string s;

    int ans = 0;
    while (ss >> s) {
      ++ans;

      for (auto c : s) {
        if (broken[c - 'a']) {
          --ans;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 66.67%
// Memory Usage: 6.7 MB, less than 100.00%