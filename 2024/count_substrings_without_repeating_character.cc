class Solution {
 public:
  int numberOfSpecialSubstrings(string s) {
    vector<int> cnt(26);
    int ans = 0;
    int n = s.size();
    for (int i = 0, j = 0; j < n; ++j) {
      ++cnt[s[j] - 'a'];
      while (cnt[s[j] - 'a'] > 1) {
        --cnt[s[i] - 'a'];
        ++i;
      }

      ans += j - i + 1;
    }

    return ans;
  }
};
// 69 ms
// 20.24 MB