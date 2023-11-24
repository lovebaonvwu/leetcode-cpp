class Solution {
 public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    return helper(firstWord) + helper(secondWord) == helper(targetWord);
  }

  int helper(const string& s) {
    int n = 0;

    for (auto c : s) {
      n = n * 10 + (c - 'a');
    }

    return n;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 81.82%