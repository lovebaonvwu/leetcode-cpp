class Solution {
 public:
  string modifyString(string s) {
    for (int i = 0, n = s.size(); i < n; ++i) {
      if (s[i] == '?') {
        for (s[i] = 'a'; s[i] <= 'c'; ++s[i]) {
          if ((i == 0 || s[i] != s[i - 1]) &&
              (i == n - 1 || s[i] != s[i + 1])) {
            break;
          }
        }
      }
    }

    return s;
  }
};
// Runtime: 4 ms, faster than 30.52%
// Memory Usage: 6.4 MB, less than 100.00%

class Solution {
 public:
  string modifyString(string s) {
    for (int i = 0, n = s.size(); i < n; ++i) {
      if (s[i] == '?') {
        for (s[i] = 'a'; s[i] <= 'c'; ++s[i]) {
          if (i == 0 && i + 1 < n && s[i] != s[i + 1]) {
            break;
          } else if (i == n - 1 && s[i] != s[i - 1]) {
            break;
          } else if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            break;
          }
        }
      }
    }

    return s;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 100.00%