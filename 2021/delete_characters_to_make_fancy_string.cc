class Solution {
 public:
  string makeFancyString(string s) {
    string ans = s.substr(0, 2);

    for (int i = 2; i < s.size(); ++i) {
      if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
        continue;
      }

      ans += s[i];
    }

    return ans;
  }
};
// Runtime: 132 ms, faster than 16.67%
// Memory Usage: 41.1 MB, less than 16.67%
// 2021.8.9 at 奥盛大厦