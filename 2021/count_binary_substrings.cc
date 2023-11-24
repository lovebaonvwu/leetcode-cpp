class Solution {
 public:
  int countBinarySubstrings(string s) {
    int one = s[0] == '1' ? 1 : 0;
    int zero = s[0] == '0' ? 1 : 0;

    int ans = 0;

    s.push_back('2');

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        ans += min(one, zero);

        s[i] == '0' ? (zero = 1) : (one = 1);
      } else {
        s[i] == '0' ? ++zero : ++one;
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 68.93%
// Memory Usage: 12 MB, less than 27.60%

class Solution {
 public:
  int countBinarySubstrings(string s) {
    int one = s[0] == '1' ? 1 : 0;
    int zero = s[0] == '0' ? 1 : 0;

    int ans = 0;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        ans += min(one, zero);

        s[i] == '0' ? (zero = 1) : (one = 1);
      } else {
        s[i] == '0' ? ++zero : ++one;
      }
    }

    return ans + min(one, zero);
  }
};
// Runtime: 32 ms, faster than 38.02%
// Memory Usage: 10.7 MB, less than 67.77%