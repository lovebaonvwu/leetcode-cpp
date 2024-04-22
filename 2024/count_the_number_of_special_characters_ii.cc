class Solution {
 public:
  int numberOfSpecialChars(string word) {
    vector<int> uppers(26);
    vector<int> lowers(26);
    vector<int> cnt(26);

    int ans = 0;
    for (auto c : word) {
      if (c >= 'a' && c <= 'z') {
        if (cnt[c - 'a'] == -1)
          continue;
        ++lowers[c - 'a'];
        if (cnt[c - 'a'] > 0) {
          --ans;
          cnt[c - 'a'] = -1;
        }
      } else {
        if (cnt[c - 'A'] == -1)
          continue;
        if (uppers[c - 'A'] == 0 && lowers[c - 'A'] > 0) {
          ++ans;
          ++cnt[c - 'A'];
        }
        ++uppers[c - 'A'];
      }
    }

    return ans;
  }
};
// 66 ms
// 22.83 MB