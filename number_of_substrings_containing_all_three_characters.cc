class Solution {
 public:
  int numberOfSubstrings(string s) {
    int ans = 0, n = s.size();

    for (int i = 0; i < n; ++i) {
      int k = 0;
      for (int j = i, cnt = 0; j < n; ++j) {
        cnt |= 1 << (s[j] - 'a');

        if (cnt == 0b111) {
          k = j;
          break;
        }
      }

      if (!k) {
        break;
      }

      ans += n - k;
    }

    return ans;
  }
};
// Runtime: 1724 ms, faster than 5.35%
// Memory Usage: 8.3 MB, less than 92.48%

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int ans = 0, i = 0, n = s.size();
    int cnt[3] = {0};

    for (int j = 0; j < n; ++j) {
      ++cnt[s[j] - 'a'];

      while (cnt[0] && cnt[1] && cnt[2]) {
        --cnt[s[i++] - 'a'];
      }

      ans += i;
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 75.05%
// Memory Usage: 8.5 MB, less than 72.08%