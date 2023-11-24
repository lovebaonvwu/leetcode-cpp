class Solution {
 public:
  int minOperations(string s) {
    string t = s;
    t[0] = (1 - (t[0] - '0')) + '0';

    int tc = 1, sc = 0;

    for (int i = 1; i < t.size(); ++i) {
      if (t[i] == t[i - 1]) {
        t[i] = (1 - (t[i - 1] - '0')) + '0';
        ++tc;
      }

      if (s[i] == s[i - 1]) {
        s[i] = (1 - (s[i - 1] - '0')) + '0';
        ++sc;
      }
    }

    return min(tc, sc);
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 50.00%

class Solution {
 public:
  int minOperations(string s) {
    int cnt = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] - '0' != i % 2) {
        ++cnt;
      }
    }

    return min(cnt, n - cnt);
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 7 MB, less than 50.00%