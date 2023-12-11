class Solution {
 public:
  int removeAlmostEqualCharacters(string word) {
    int ans = 0;
    for (int i = 1; i < word.size(); ++i) {
      if (word[i] == word[i - 1] || abs(word[i] - word[i - 1]) == 1) {
        ++ans;
        ++i;
      }
    }

    return ans;
  }
};
// 0ms
// 6.59MB

class Solution {
 public:
  int removeAlmostEqualCharacters(string word) {
    int ans = 0;
    for (int i = 1; i < word.size(); ++i) {
      if (abs(word[i] - word[i - 1]) <= 1) {
        ++ans;
        ++i;
      }
    }

    return ans;
  }
};
// 0ms
// 6.61MB