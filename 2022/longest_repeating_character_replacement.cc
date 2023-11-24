class Solution {
 public:
  int characterReplacement(string s, int k) {
    int cnt[26] = {0};

    int maxCnt = 0;

    int ans = 0;

    for (int i = 0, j = 0; j < s.size(); ++j) {
      ++cnt[s[j] - 'A'];
      maxCnt = *max_element(begin(cnt), end(cnt));

      if ((j - i + 1) - maxCnt > k) {
        --cnt[s[i] - 'A'];
        ++i;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 78.08%
// Memory Usage: 7.1 MB, less than 11.77%
// 2022.1.4 at 奥盛大厦

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int cnt[26] = {0};

    int maxCnt = 0;

    int ans = 0;

    for (int i = 0, j = 0; j < s.size(); ++j) {
      ++cnt[s[j] - 'A'];
      maxCnt = *max_element(begin(cnt), end(cnt));

      if ((j - i + 1) - maxCnt > k) {
        --cnt[s[i] - 'A'];
        ++i;
      }

      ans = max(ans, (j - 1) - (i - 1) + 1);
    }

    return ans;
  }
};
// Runtime: 30 ms, faster than 12.71%
// Memory Usage: 7.1 MB, less than 48.19%
// 2022.1.4 at 奥盛大厦