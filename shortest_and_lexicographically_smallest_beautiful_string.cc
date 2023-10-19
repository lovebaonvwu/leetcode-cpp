class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    string ans;
    int minlen = s.size() + 1;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        continue;
      }

      int cnt = 0;
      int j = i;
      for (; j < n; ++j) {
        cnt += s[j] == '1';
        if (cnt == k) {
          break;
        }
      }

      if (cnt == k) {
        if (j - i + 1 < minlen) {
          minlen = j - i + 1;
          ans = s.substr(i, j - i + 1);
        } else if (j - i + 1 == minlen) {
          ans = min(ans, s.substr(i, j - i + 1));
        }
      }
    }

    return ans;
  }
};
// 0ms
// 6.58MB