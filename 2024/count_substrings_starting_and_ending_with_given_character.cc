class Solution {
 public:
  long long countSubstrings(string s, char c) {
    long long ans = 0;
    int cnt = 0;
    for (auto ch : s) {
      if (ch == c) {
        ++cnt;
        ans += cnt;
      }
    }

    return ans;
  }
};
// 12 ms
// 11.30 MB