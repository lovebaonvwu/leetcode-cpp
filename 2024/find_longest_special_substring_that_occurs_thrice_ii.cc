class Solution {
 public:
  int maximumLength(string s) {
    map<pair<char, int>, int> mp;
    s.append(1, '*');
    for (int i = 1, cnt = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        for (int j = 1; j <= cnt; ++j) {
          mp[{s[i - 1], j}] += cnt - j + 1;
        }

        cnt = 1;
      } else {
        ++cnt;
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
// 1377ms
// 274.41MB