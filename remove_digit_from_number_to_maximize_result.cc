class Solution {
 public:
  string removeDigit(string number, char digit) {
    int offset = 0, pos = 0;

    string ans;
    while ((pos = number.find(digit, offset)) != std::string::npos) {
      string s = number.substr(0, pos) + number.substr(pos + 1);
      ans = max(ans, s);
      offset = pos + 1;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.9 MB, less than 39.11%
// 2022.5.28 at 奥盛大厦