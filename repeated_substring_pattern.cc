class Solution {
  string leftShift(string& s, int i) {
    string result = s.substr(i);

    return result += s.substr(0, i);
  }

 public:
  bool repeatedSubstringPattern(string s) {
    for (int i = 1; i <= s.size() / 2; ++i) {
      if (s.size() % i == 0) {
        string rotateString = leftShift(s, i);
        if (rotateString == s) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 56 ms, faster than 70.80%
// Memory Usage: 108.2 MB, less than 14.99%