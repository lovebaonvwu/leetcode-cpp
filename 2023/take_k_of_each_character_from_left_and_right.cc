class Solution {
 public:
  int takeCharacters(string s, int k) {
    int cnt[3] = {};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }
    if (*min_element(begin(cnt), end(cnt)) < k) {
      return -1;
    }

    int n = s.size();
    int ans = -1;
    for (int i = 0, j = 0; i < n; ++i) {
      if (--cnt[s[i] - 'a'] < k) {
        while (cnt[s[i] - 'a'] < k) {
          ++cnt[s[j++] - 'a'];
        }
      }

      ans = max(ans, i - j + 1);
    }

    return n - ans;
  }
};
// Runtime 31 ms
// Memory 10.5 MB