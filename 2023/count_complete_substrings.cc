class Solution {
 public:
  int countCompleteSubstrings(string word, int k) {
    int ans = 0;
    for (int ch = 1; ch <= 26; ++ch) {
      int cnt[26]{0};
      for (int i = 0, j = 0; i < word.size(); ++i) {
        if (i > 0 && abs(word[i] - word[i - 1]) > 2) {
          memset(cnt, 0, sizeof(cnt));
          j = i;
        }

        ++cnt[word[i] - 'a'];
        if (i - j + 1 > ch * k) {
          --cnt[word[j++] - 'a'];
        }

        int total = 0;
        for (int p = 0; p < 26; ++p) {
          if (cnt[p] > 0 && cnt[p] != k) {
            total = 0;
            break;
          }

          if (cnt[p] == k)
            ++total;
        }
        if (total == ch)
          ++ans;
      }
    }

    return ans;
  }
};
// 1246ms
// 16.73MB