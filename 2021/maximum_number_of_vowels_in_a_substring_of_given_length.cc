class Solution {
  bool isVowels(char c) {
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
      default:
        return false;
    }
  }

 public:
  int maxVowels(string s, int k) {
    int cnt = 0;

    for (int i = 0; i < k; ++i) {
      if (isVowels(s[i])) {
        ++cnt;
      }
    }

    int ans = cnt;
    for (int i = k; i < s.size(); ++i) {
      if (isVowels(s[i])) {
        ++cnt;
      }

      if (isVowels(s[i - k])) {
        --cnt;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 50.00%
// Memory Usage: 10.1 MB, less than 100.00%

class Solution {
 public:
  int maxVowels(string s, int k) {
    int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
                      0, 0, 0, 1, 0, 0, 0, 0, 0, 1};

    int ans = 0;

    for (int i = 0, cnt = 0; i < s.size(); ++i) {
      cnt += vowels[s[i] - 'a'];

      if (i >= k) {
        cnt -= vowels[s[i - k] - 'a'];
      }

      ans = max(cnt, ans);
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 75.00%
// Memory Usage: 9.9 MB, less than 100.00%