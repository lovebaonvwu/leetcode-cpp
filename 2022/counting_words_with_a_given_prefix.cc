class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    int ans = 0;

    for (auto& w : words) {
      if (w.size() < pref.size()) {
        continue;
      }

      int i = 0;

      while (i < pref.size() && pref[i] == w[i]) {
        ++i;
      }
      ans += i == pref.size();
    }

    return ans;
  }
};
// Runtime: 9 ms, faster than 87.78%
// Memory Usage: 9.8 MB, less than 91.16%
// 2022.3.2 at 茗筑美嘉