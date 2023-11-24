class Solution {
 public:
  int secondsToRemoveOccurrences(string s) {
    int ans = 0;

    while (true) {
      string t = s;
      for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '1') {
          t[i] = '1';
          t[i + 1] = '0';
        }
      }

      if (t == s) {
        break;
      } else {
        ++ans;
        swap(s, t);
      }
    }

    return ans;
  }
};
// Runtime: 159 ms, faster than 30.00%
// Memory Usage: 42.9 MB, less than 10.00%
// 2022.8.21 at 茗筑美嘉