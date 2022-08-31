class Solution {
 public:
  string removeStars(string s) {
    vector<char> stk;

    for (auto c : s) {
      if (c == '*') {
        stk.pop_back();
        continue;
      }

      stk.push_back(c);
    }

    return string(stk.begin(), stk.end());
  }
};
// Runtime: 244 ms, faster than 8.15%
// Memory Usage: 26.8 MB, less than 49.96%
// 2022.8.31 at 奥盛大厦