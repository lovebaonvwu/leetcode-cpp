class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    int n = s.size();
    for (int i = n - 1, j = n - 1; j >= 0; --j) {
      if (s[j] == '1') {
        swap(s[j], s[i]);
        break;
      }
    }

    for (int i = 0, j = 0; j < n - 1; ++j) {
      if (s[j] == '1') {
        swap(s[i++], s[j]);
      }
    }

    return s;
  }
};
// 0ms
// 6.75MB