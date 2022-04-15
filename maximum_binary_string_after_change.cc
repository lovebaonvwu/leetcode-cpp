class Solution {
 public:
  string maximumBinaryString(string binary) {
    int i = 0;
    string& s = binary;

    while (s[i] == '1') {
      ++i;
    }

    int zeros = 0;
    for (int j = i; j < s.size(); ++j) {
      zeros += s[j] == '0';
    }

    if (zeros < 2) {
      return s;
    }

    while (zeros-- > 0) {
      s[i++] = '1';
    }

    s[i - 1] = '0';

    while (i < s.size()) {
      s[i++] = '1';
    }

    return s;
  }
};
// Runtime: 137 ms, faster than 98.00%
// Memory Usage: 45.8 MB, less than 36.50%
// 2022.4.15 at 奥盛大厦