class Solution {
 public:
  bool isNumber(string s) {
    return regex_match(s, regex("[-+]?(\\d+\\.?|\\.\\d+)\\d*([eE][-+]?\\d+)?"));
  }
};
// Runtime: 1728 ms, faster than 6.84%
// Memory Usage: 264.1 MB, less than 5.10%

class Solution {
 public:
  bool isNumber(string s) {
    int i = 0, j = s.size() - 1;

    while (s[i] == ' ') {
      ++i;
    }

    while (s[j] == ' ') {
      --j;
    }

    bool seenDot = false;
    bool seenE = false;
    bool seenNumber = false;
    bool seenNumberAfterE = true;

    for (int k = i; k <= j; ++k) {
      if (isdigit(s[k])) {
        seenNumber = true;

        if (seenE) {
          seenNumberAfterE = true;
        }
      } else if (s[k] == 'e' || s[k] == 'E') {
        if (seenE || !seenNumber) {
          return false;
        }

        seenE = true;
        seenNumberAfterE = false;
      } else if (s[k] == '.') {
        if (seenDot || seenE) {
          return false;
        }

        seenDot = true;
      } else if (s[k] == '+' || s[k] == '-') {
        if (!(k == i || s[k - 1] == 'e' || s[k - 1] == 'E')) {
          return false;
        }
      } else {
        return false;
      }
    }

    return seenNumber && seenNumberAfterE;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 56.06%