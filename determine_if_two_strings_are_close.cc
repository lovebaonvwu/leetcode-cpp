class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }

    vector<int> w1(26), w2(26);

    for (int i = 0; i < word1.size(); ++i) {
      ++w1[word1[i] - 'a'];
      ++w2[word2[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (w1[i] > 0 && w2[i] == 0 || w1[i] == 0 && w2[i] > 0) {
        return false;
      }
    }

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    for (int i = 0; i < 26; ++i) {
      if (w1[i] != w2[i]) {
        return false;
      }
    }

    return true;
  }
};
// 84 ms
// 20.5 MB