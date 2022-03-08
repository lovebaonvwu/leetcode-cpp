class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int chs[26] = {0};

    unordered_map<string, int> mp;

    int ans = 0;

    for (int i = 0, j = 0, cnt = 0; i < s.size();) {
      if (++chs[s[i++] - 'a'] == 1) {
        ++cnt;
      }

      while (cnt > maxLetters || i - j > minSize) {
        if (--chs[s[j++] - 'a'] == 0) {
          --cnt;
        }
      }

      if (i - j == minSize) {
        ans = max(ans, ++mp[s.substr(j, minSize)]);
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 99.07%
// Memory Usage: 13.2 MB, less than 86.54%
// 2022.3.8 at 奥盛大厦