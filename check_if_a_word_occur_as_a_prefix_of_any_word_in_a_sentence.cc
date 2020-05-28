class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    stringstream ss(sentence);

    string s;
    int idx = 1;
    int ans = -1;
    while (ss >> s) {
      bool notMatch = false;
      for (int i = 0; i < searchWord.size(); ++i) {
        if (searchWord[i] != s[i]) {
          notMatch = true;
        }
      }

      if (!notMatch) {
        ans = idx;
        break;
      }
      ++idx;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 100.00%

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    string s = ' ' + sentence;
    string w = ' ' + searchWord;

    auto p = s.find(w);

    if (p != string::npos) {
      return count(s.begin(), s.begin() + p + 1, ' ');
    }

    return -1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%