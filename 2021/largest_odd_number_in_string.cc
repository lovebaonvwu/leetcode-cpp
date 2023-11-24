class Solution {
 public:
  string largestOddNumber(string num) {
    int n = num.size();

    for (int i = n - 1; i >= 0; --i) {
      if ((num[i] - '0') & 1) {
        return num.substr(0, i + 1);
      }
    }

    return "";
  }
};
// Runtime: 28 ms, faster than 85.10%
// Memory Usage: 14.9 MB, less than 49.68%