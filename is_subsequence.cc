class Solution {
 public:
  bool isSubsequence(string s, string t) { return isSub(s, t, 0, 0); }

  bool isSub(string& s, string& t, int si, int ti) {
    if (si == s.size()) {
      return true;
    }

    if (ti == t.size()) {
      return false;
    }

    ti = t.find(s[si], ti);
    if (ti == string::npos) {
      return false;
    }

    return isSub(s, t, si + 1, ti + 1);
  }
};
// Runtime: 52 ms, faster than 97.29%
// Memory Usage: 17.2 MB, less than 19.05%

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i, ++j) {
      while (j < t.size() && t[j] != s[i]) {
        ++j;
      }

      if (j == t.size()) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 56 ms, faster than 95.56%
// Memory Usage: 17.2 MB, less than 19.05%

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0;
    for (int j = 0; j < t.size() && i < s.size(); ++j) {
      if (s[i] == t[j]) {
        ++i;
      }
    }

    return i == s.size();
  }
};
// Runtime: 64 ms, faster than 61.04%
// Memory Usage: 17 MB, less than 85.71%