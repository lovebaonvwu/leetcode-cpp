class Solution {
 public:
  int maximumLength(string s) {
    map<pair<char, int>, int> mp;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      mp[{s[i], 1}] += 1;
      for (int j = i + 1; j < n && s[j] == s[j - 1]; ++j) {
        mp[{s[i], j - i + 1}] += 1;
      }
    }

    int ans = -1;
    for (auto& [p, cnt] : mp) {
      if (cnt >= 3) {
        ans = max(ans, p.second);
      }
    }

    return ans;
  }
};
// 17ms
// 8.42MB