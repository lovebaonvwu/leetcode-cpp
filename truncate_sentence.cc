class Solution {
 public:
  string truncateSentence(string s, int k) {
    string ans, word;

    s += ' ';
    for (auto c : s) {
      if (c == ' ' && !word.empty() && k-- > 0) {
        if (!ans.empty()) {
          ans += ' ';
        }

        ans += word;
        word.clear();
      } else {
        word += c;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 100.00%

class Solution {
 public:
  string truncateSentence(string s, int k) {
    string ans, word;

    s += ' ';
    for (int i = 0; i < s.size() && k > 0; ++i) {
      if (s[i] == ' ') {
        if (!ans.empty()) {
          ans += ' ';
        }

        ans += word;
        word.clear();

        --k;
      } else {
        word += s[i];
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 100.00%

class Solution {
 public:
  string truncateSentence(string s, int k) {
    stringstream ss(s);

    string ans, word;

    while (ss >> word && k-- > 0) {
      if (!ans.empty()) {
        ans += ' ';
      }
      ans += word;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 100.00%