class Solution {
 public:
  int minimumTimeToInitialState(string word, int k) {
    int n = word.size() / k;
    for (int i = 1; i <= n; ++i) {
      if (word.substr(i * k) == word.substr(0, word.size() - i * k)) {
        return i;
      }
    }

    return word.size() % k == 0 ? n : n + 1;
  }
};
// 0 ms
// 8.52 MB