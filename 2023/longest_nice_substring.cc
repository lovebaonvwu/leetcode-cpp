class Solution {
 public:
  string longestNiceSubstring(string s) {
    int n = s.size();
    for (int len = n; len >= 2; --len) {
      for (int i = 0; i <= n - len; ++i) {
        string t = s.substr(i, len);
        int ch[256] = {0};
        for (auto c : t) {
          ++ch[c];
        }

        bool valid = true;
        for (int k = 'a'; k <= 'z'; ++k) {
          if (ch[k] > 0 && ch[k - 'a' + 'A'] == 0 ||
              ch[k] == 0 && ch[k - 'a' + 'A'] > 0) {
            valid = false;
            break;
          }
        }

        if (valid) {
          return t;
        }
      }
    }

    return "";
  }
};
// Runtime 51 ms
// Memory 11.3 MB
// 2022.11.21 at 茗筑美嘉