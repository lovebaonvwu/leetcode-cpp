class Solution {
 public:
  int removePalindromeSub(string s) {
    return s.empty() ? 0 : (s == string(s.rbegin(), s.rend()) ? 1 : 2);
  }
};
// Runtime: 4 ms, faster than 69.35%
// Memory Usage: 8.7 MB, less than 100.00%