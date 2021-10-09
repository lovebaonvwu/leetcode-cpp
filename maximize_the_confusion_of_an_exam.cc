class Solution {
  int helper(string s, int k, char c) {
    int i = 0, j = 0;

    for (; j < s.size(); ++j) {
      if (s[j] == c) {
        --k;
      }

      if (k < 0) {
        if (s[i] == c) {
          ++k;
        }

        ++i;
      }
    }

    return j - i;
  }

 public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    return max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
  }
};
// Runtime: 28 ms, faster than 82.36%
// Memory Usage: 11.8 MB, less than 34.53%
// 2021.10.9 at 奥盛大厦