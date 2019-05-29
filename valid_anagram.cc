class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }

    int count[26]{0};

    for (int i = 0; i < s.size(); ++i) {
      count[s[i] - 'a']++;
      count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; ++i) {
      if (count[i] != 0) {
        return false;
      }
    }

    return true;
  }
};  // 8ms

class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> vs(26);
    vector<int> vt(26);

    for (char& c : s) {
      vs[c - 97] += 1;
    }

    for (char& c : t) {
      vt[c - 97] += 1;
    }

    for (int i = 0; i < 26; ++i) {
      if (vt[i] != vs[i]) {
        return false;
      }
    }

    return true;
  }
};  // 12ms