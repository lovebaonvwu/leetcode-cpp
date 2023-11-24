class Solution {
 public:
  bool checkAlmostEquivalent(string word1, string word2) {
    int cnt1[26] = {0};
    int cnt2[26] = {0};

    int n = word1.size();
    for (int i = 0; i < n; ++i) {
      ++cnt1[word1[i] - 'a'];
      ++cnt2[word2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (abs(cnt1[i] - cnt2[i]) > 3) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 7 ms, faster than 7.69%
// Memory Usage: 6.2 MB, less than 100.00%
// 2021.11.14 at 茗筑美嘉