class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    string ans = "";

    for (auto& w : d) {
      int sp = 0, wp = 0;

      while (sp < s.size() && wp < w.size()) {
        if (w[wp] == s[sp]) {
          ++wp;
          ++sp;
        } else {
          ++sp;
        }
      }

      if (wp == w.size()) {
        if (w.size() > ans.size()) {
          ans = w;
        } else if (w.size() == ans.size() && w < ans) {
          ans = w;
        }
      }
    }

    return ans;
  }
};
// Runtime: 52 ms, faster than 96.56%
// Memory Usage: 14.9 MB, less than 82.09%