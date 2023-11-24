class Solution {
 public:
  int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.size(), b.size());
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 90.82%