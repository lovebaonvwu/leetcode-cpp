class Solution {
 public:
  string toHex(int num) {
    if (num == 0) {
      return "0";
    }

    char hex[] = "0123456789abcdef";

    string ans;

    unsigned int unum = static_cast<unsigned int>(num);

    while (unum > 0) {
      ans = hex[unum & 0xf] + ans;

      unum >>= 4;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 60.49%
// 2022.3.15 at 奥盛大厦