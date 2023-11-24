class Solution {
 public:
  string removeOccurrences(string s, string part) {
    while (s.find(part) != string::npos) {
      auto p = s.find(part);

      s = s.substr(0, p) + s.substr(p + part.size());
    }

    return s;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 8.1 MB, less than 20.00%