class Solution {
 public:
  string lastNonEmptyString(string s) {
    unordered_map<char, int> mp;
    int max_cnt = 0;
    for (auto c : s) {
      ++mp[c];
      max_cnt = max(max_cnt, mp[c]);
    }

    vector<bool> removed(26);
    for (auto [k, cnt] : mp) {
      if (cnt < max_cnt) {
        removed[k - 'a'] = true;
      }
    }

    string ans;
    for (auto c : s) {
      if (!removed[c - 'a']) {
        if (mp[c]-- == 1) {
          ans += c;
        }
      }
    }

    return ans;
  }
};
// 272 ms
// 32.20 MB