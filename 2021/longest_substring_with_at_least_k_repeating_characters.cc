class Solution {
 public:
  int longestSubstring(string s, int k) {
    int ans = 0;

    for (int i = 0; i + k <= s.size();) {
      int cnt[26] = {0};

      int end = i;
      for (int j = i, mask = 0; j < s.size(); ++j) {
        int idx = s[j] - 'a';

        ++cnt[idx];

        if (cnt[idx] < k) {
          mask |= (1 << idx);
        } else {
          mask &= (~(1 << idx));
        }

        if (mask == 0) {
          ans = max(ans, j - i + 1);
          end = j;
        }
      }

      i = end + 1;
    }

    return ans;
  }
};
// Runtime: 272 ms, faster than 7.97%
// Memory Usage: 6.6 MB, less than 86.85%

class Solution {
 public:
  int longestSubstring(string s, int k) { return dfs(s, k, 0, s.size()); }

  int dfs(string& s, int k, int lo, int hi) {
    int cnt[26] = {0};

    for (int i = lo; i < hi; ++i) {
      ++cnt[s[i] - 'a'];
    }

    int ans = 0;

    for (int i = lo; i < hi;) {
      while (i < hi && cnt[s[i] - 'a'] < k) {
        ++i;
      }

      if (i == hi) {
        break;
      }

      int end = i;

      while (end < hi && cnt[s[end] - 'a'] >= k) {
        ++end;
      }

      if (i == lo && end == hi) {
        return hi - lo;
      }

      ans = max(ans, dfs(s, k, i, end));

      i = end;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 72.64%