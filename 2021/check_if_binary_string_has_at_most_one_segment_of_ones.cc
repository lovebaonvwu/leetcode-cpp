class Solution {
 public:
  bool checkOnesSegment(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        continue;
      }

      for (int j = i + 1; j < s.size(); ++j) {
        if (s[j] == '1') {
          return false;
        }
      }

      break;
    }

    return true;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%

class Solution {
 public:
  bool checkOnesSegment(string s) {
    int i = 0;

    while (i < s.size() && s[i] == '1') {
      ++i;
    }

    while (i < s.size() && s[i] == '0') {
      ++i;
    }

    return i == s.size();
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%