class Solution {
 public:
  string reversePrefix(string word, char ch) {
    auto pos = word.find(ch);

    if (pos != std::string::npos) {
      for (int i = 0; i < pos; ++i, --pos) {
        swap(word[i], word[pos]);
      }
    }

    return word;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 33.11%
// 2021.9.14 at 奥盛大厦