class Solution {
 public:
  int maximumLengthSubstring(string s) {
    vector<int> cnt(26);
    int n = s.size();
    int ans = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      ++cnt[s[j] - 'a'];
      while (any_of(begin(cnt), end(cnt), [](int c) { return c > 2; })) {
        --cnt[s[i++] - 'a'];
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// 0 ms
// 7.96 MB