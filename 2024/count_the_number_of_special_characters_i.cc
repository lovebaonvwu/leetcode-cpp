class Solution {
 public:
  int numberOfSpecialChars(string word) {
    vector<int> uppers(26);
    vector<int> lowers(26);
    vector<int> cnt(26);

    int ans = 0;
    for (auto c : word) {
      if (c >= 'A' && c <= 'Z') {
        ++uppers[c - 'A'];
        if (lowers[c - 'A'] && cnt[c - 'A'] == 0) {
          ++ans;
          ++cnt[c - 'A'];
        }
      } else {
        ++lowers[c - 'a'];
        if (uppers[c - 'a'] && cnt[c - 'a'] == 0) {
          ++ans;
          ++cnt[c - 'a'];
        }
      }
    }

    return ans;
  }
};
// 0 ms
// 8.31 MB