class Solution {
 public:
  int numKLenSubstrNoRepeats(string s, int k) {
    if (k > 26 || k > s.size()) {
      return 0;
    }

    int cnt[26] = {0};
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      ++cnt[s[i] - 'a'];

      if (i >= k) {
        --cnt[s[i - k] - 'a'];
      }

      if (i >= k - 1) {
        bool norepeat = true;
        for (int j = 0; j < 26; ++j) {
          if (cnt[j] > 1) {
            norepeat = false;
            break;
          }
        }

        ans += norepeat;
      }
    }

    return ans;
  }
};
// Runtime 3 ms
// Memory 6.6 MB
// 2023.1.29 at 茗筑美嘉