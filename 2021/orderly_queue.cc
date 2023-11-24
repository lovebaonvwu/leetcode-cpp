class Solution {
 public:
  string orderlyQueue(string s, int k) {
    if (k > 1) {
      sort(s.begin(), s.end());

      return s;
    }

    string ans = s;

    for (int i = 1; i < s.size(); ++i) {
      ans = min(ans, s.substr(i) + s.substr(0, i));
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 75.00%
// Memory Usage: 10.9 MB, less than 33.16%
// 2021.9.5 at 茗筑美嘉