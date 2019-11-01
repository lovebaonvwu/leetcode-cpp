class Solution {
 public:
  string shiftingLetters(string S, vector<int>& shifts) {
    for (int i = shifts.size() - 2; i >= 0; --i) {
      shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
    }

    for (int i = 0; i < S.size(); ++i) {
      S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
    }

    return S;
  }
};
// Runtime: 56 ms, faster than 64.90%
// Memory Usage: 11.6 MB, less than 75.00%

class Solution {
 public:
  string shiftingLetters(string S, vector<int>& shifts) {
    int sum = 0;
    for (int i = S.size() - 1; i >= 0; --i) {
      sum += shifts[i];
      sum %= 26;

      S[i] = (S[i] - 'a' + sum) % 26 + 'a';
    }

    return S;
  }
};
// Runtime: 80 ms, faster than 5.90%
// Memory Usage: 11.5 MB, less than 100.00%