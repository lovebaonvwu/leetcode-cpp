class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int ans = 0, n = s.size();

    for (int k = 0; k < 26; ++k) {
      int i = 0, j = n - 1;

      while (i < n && s[i] != ('a' + k)) {
        ++i;
      }

      while (j >= 0 && s[j] != ('a' + k)) {
        --j;
      }

      int cnt = 0;
      int seen[26] = {0};
      for (int p = i + 1; p < j; ++p) {
        if (!seen[s[p] - 'a']) {
          seen[s[p] - 'a'] = 1;
          ++cnt;
        }
      }

      ans += cnt;
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 63.64%
// Memory Usage: 11 MB, less than 100.00%
// 2021.7.12 at 奥盛大厦

class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int ans = 0, n = s.size();
    int left[26] = {[0 ... 25] = INT_MAX}, right[26] = {0};

    for (int i = 0; i < n; ++i) {
      left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
      right[s[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; ++i) {
      if (left[i] < right[i]) {
        ans +=
            unordered_set<char>(s.begin() + left[i] + 1, s.begin() + right[i])
                .size();
      }
    }

    return ans;
  }
};
// Runtime: 328 ms, faster than 54.55%
// Memory Usage: 151.9 MB, less than 18.18%
// 2021.7.12 at 奥盛大厦