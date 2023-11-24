class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    int i = 0;

    for (int j = 0; i < s.size() && j < words.size(); ++j) {
      for (auto c : words[j]) {
        if (i == s.size() || s[i++] != c) {
          return false;
        }
      }
    }

    return i == s.size();
  }
};
// Runtime: 4 ms, faster than 80.83%
// Memory Usage: 13.9 MB, less than 72.78%
// 2021.8.10 at 奥盛大厦

class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    string t;

    for (auto& w : words) {
      if (t.size() > s.size()) {
        return false;
      }

      t += w;

      if (s == t) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 80.83%
// Memory Usage: 14 MB, less than 45.71%
// 2021.8.10 at 奥盛大厦