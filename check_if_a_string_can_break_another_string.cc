class Solution {
 public:
  bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int i = 0;

    while (s1[i] == s2[i]) {
      ++i;
    }

    if (s1[i] < s2[i]) {
      swap(s1, s2);
    }

    for (; i < s1.size(); ++i) {
      if (s1[i] < s2[i]) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 396 ms, faster than 76.55%
// Memory Usage: 11.5 MB, less than 100.00%

class Solution {
 public:
  bool checkIfCanBreak(string s1, string s2) {
    int c1[26] = {};
    int c2[26] = {};

    for (int i = 0; i < s1.size(); ++i) {
      ++c1[s1[i] - 'a'];
      ++c2[s2[i] - 'a'];
    }

    int p1 = 0;
    int p2 = 0;
    int b1 = 0;
    int b2 = 0;

    for (int i = 0; i < 26; ++i) {
      p1 += c1[i];
      p2 += c2[i];

      if (p1 < p2) {
        b1 = 1;
      }

      if (p2 < p1) {
        b2 = 1;
      }
    }

    return !(b1 & b2);
  }
};
// Runtime: 76 ms, faster than 99.77%
// Memory Usage: 11.6 MB, less than 100.00%