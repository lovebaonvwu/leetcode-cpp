class Solution {
 public:
  int maxScore(string s) {
    int ones = 0;

    for (auto c : s) {
      if (c == '1') {
        ++ones;
      }
    }

    int ans = s[0] == '0' ? ones + 1 : ones - 1;

    int score = ans;
    for (int i = 1; i < s.size() - 1; ++i) {
      if (s[i] == '0') {
        ++score;
      } else {
        --score;
      }
      ans = max(ans, score);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 75.92%
// Memory Usage: 6.3 MB, less than 100.00%

class Solution {
 public:
  int maxScore(string s) {
    int score = 0;

    for (auto c : s) {
      if (c == '1') {
        ++score;
      }
    }

    int ans = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
      s[i] == '0' ? ++score : --score;

      ans = max(ans, score);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 75.92%
// Memory Usage: 6.5 MB, less than 100.00%