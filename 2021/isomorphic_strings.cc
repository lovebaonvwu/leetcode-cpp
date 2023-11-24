class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t, t2s;

    for (int i = 0; i < s.length(); i++) {
      if (!s2t[s[i]] && !t2s[t[i]]) {
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
      } else if (s2t[s[i]] == t[i] && t2s[t[i]] == s[i]) {
        continue;
      } else {
        return false;
      }
    }

    return true;
  }
};  // 8ms

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char s2t[127]{0}, t2s[127]{0};

    for (int i = 0; i < s.length(); i++) {
      if (!s2t[s[i]] && !t2s[t[i]]) {
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
      } else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) {
        return false;
      }
    }

    return true;
  }
};  // 8ms