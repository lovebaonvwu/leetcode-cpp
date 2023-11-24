class Solution {
 public:
  int countPrefixes(vector<string>& words, string s) {
    int ans = 0;

    for (auto& w : words) {
      int i = 0;

      while (i < w.size() && w[i] == s[i]) {
        ++i;
      }

      ans += i == w.size();
    }

    return ans;
  }
};
// Runtime: 17 ms, faster than 14.29%
// Memory Usage: 12 MB, less than 14.29%
// 2022.5.2 at 茗筑美嘉