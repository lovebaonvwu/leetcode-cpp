class Solution {
 public:
  string removeTrailingZeros(string num) {
    int i = num.size() - 1;
    while (num[i] == '0') {
      --i;
    }

    return num.substr(0, i + 1);
  }
};
// Runtime 14 ms
// Memory 9 MB