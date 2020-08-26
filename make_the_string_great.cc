class Solution {
 public:
  string makeGood(string s) {
    string ans = "";

    for (auto c : s) {
      if (!ans.empty() && abs(c - ans.back()) == 32) {
        ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 60.17%

class Solution {
 public:
  string makeGood(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (p > 0 && abs(s[i] - s[p - 1]) == 32) {
        --p;
      } else {
        s[p++] = s[i];
      }
    }

    return s.substr(0, p);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 62.29%