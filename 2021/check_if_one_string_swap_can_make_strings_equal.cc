class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }

    int p = -1, q = -1;

    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
        continue;
      }

      if (p < 0) {
        p = i;
      } else if (q < 0) {
        q = i;
      } else {
        return false;
      }
    }

    return p >= 0 && q >= 0 && s1[p] == s2[q] && s1[q] == s2[p];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 100.00%

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    int p = -1, q = -1;

    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) {
        continue;
      }

      if (p < 0) {
        p = i;
      } else if (q < 0) {
        q = i;
      } else {
        return false;
      }
    }

    return (p < 0 && q < 0) ||
           (p >= 0 && q >= 0 && s1[p] == s2[q] && s1[q] == s2[p]);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%