class Solution {
 public:
  string replaceDigits(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (i & 1) {
        s[i] = s[i - 1] + (s[i] - '0');
      }
    }

    return s;
  }
};
// Runtime: 4 ms, faster than 20.00%
// Memory Usage: 6.1 MB, less than 20.00%

class Solution {
 public:
  string replaceDigits(string s) {
    for (int i = 1; i < s.size(); i += 2) {
      s[i] += s[i - 1] - '0';
    }

    return s;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 80.00%