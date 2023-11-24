class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < t.size(); ++j) {
        for (int k = 0, diff = 0; i + k < s.size() && j + k < t.size(); ++k) {
          if (s[i + k] != t[j + k]) {
            ++diff;
          }

          if (diff > 1) {
            break;
          }

          ans += diff;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 85.14%

class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      ans += count(s, t, i, 0);
    }

    for (int j = 1; j < t.size(); ++j) {
      ans += count(s, t, 0, j);
    }

    return ans;
  }

  int count(string& s, string& t, int i, int j) {
    int res = 0;

    for (int cnt = 0, tmp = 0; i < s.size() && j < t.size(); ++i, ++j) {
      ++cnt;

      if (s[i] != t[j]) {
        tmp = cnt;
        cnt = 0;
      }

      res += tmp;
    }

    return res;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 85.14%