class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) {
      return false;
    }

    vector<int> s1v(26);
    vector<int> sv(26);

    for (int i = 0; i < s1.size(); ++i) {
      ++s1v[s1[i] - 'a'];
      ++sv[s2[i] - 'a'];
    }

    if (s1v == sv) {
      return true;
    }

    for (int i = s1.size(); i < s2.size(); ++i) {
      ++sv[s2[i] - 'a'];
      --sv[s2[i - s1.size()] - 'a'];

      if (sv == s1v) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 12 ms, faster than 73.66%
// Memory Usage: 9.4 MB, less than 93.75%